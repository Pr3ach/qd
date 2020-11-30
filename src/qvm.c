/*
 * This file is part of qd.
 * Copyright (C) 2020, Preacher
 * All rights reserved.
 *
 * qd is a free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * qd is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with qd.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "../color_shell/color_shell.h"
#include "../inc/qvm.h"
#include "../inc/opcodes.h"
#include "../inc/common.h"

int qvm_get_struct(char *file, qvm_t *qvm)
{
	if(!(qvm->fd = fopen(file, "rb")))
		return 0;

	fseek(qvm->fd, 0, SEEK_END);
	qvm->filesize = ftell(qvm->fd);

	qvm->filename = file;

	fseek(qvm->fd, 0, SEEK_SET);
	if(fread(&qvm->hdr, sizeof(qvm->hdr), 1, qvm->fd) != 1)
	{
		fclose(qvm->fd);
		return 0;
	}

	fseek(qvm->fd, 0, SEEK_SET);

	return 1;
}

int qvm_disasm(qvm_t *qvm, char out[QVM_MAX_LISTING][64])
{
	uint8_t op = 0;
	uint32_t arg;
	uint32_t EIP = 0;
	uint32_t i;
	uint32_t func_index = 0;

	if(!qvm->fd)
		return 0;

	fseek(qvm->fd, qvm->hdr.text_offset, SEEK_SET);

	for(i = 0; EIP < qvm->hdr.text_size && EIP < QVM_MAX_LISTING; i++, EIP += 1 + opcodes[op].arg_size){
		if(fread(&op, 1, 1, qvm->fd) != 1)
			return 0;

		if(opcodes[op].arg_size){
			arg = 0;
			if(fread(&arg, opcodes[op].arg_size, 1, qvm->fd) != 1)
				return 0;

			if(!strcmp(opcodes[op].mnemonic, "ENTER"))
			{
				strncpy(out[i++], " ", 64);
				strncpy(out[i++], "	/*", 64);
				strncpy(out[i++], raw("	 * %ssub_0x%x%s", RED_BOLD, func_index, REWIND), 64);
				strncpy(out[i++], "	 */", 64);
				func_index++;
			}

			strncpy(out[i], raw("%08x:      %s %x", EIP, opcodes[op].mnemonic, arg), 64);
			continue;
		}

		strncpy(out[i], raw("%08x:      %s", EIP, opcodes[op].mnemonic), 64);
	}

	*out[i++] = 0; /* NULL string to mark end */
	fclose(qvm->fd);

	return 1;
}
