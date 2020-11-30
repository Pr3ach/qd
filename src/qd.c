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
#include "../color_shell/color_shell.h"
#include "../inc/qd.h"

int main(int argc, char *argv[])
{
	if(argc != 2){
		printf("qd-%s/%s built on %s - by Preacher\n\n", VERSION, PLATFORM, __DATE__);
		w_bwhite("Usage: ");
		printf("%s <qvm>\n", *argv);

		return 0;
	}

	disasm((char *)argv[1]);

	return 0;
}

void disasm(char *file)
{
	uint32_t i;

	if(!(qvm = malloc(sizeof(qvm_t))))
	{
		perror("malloc");
		exit(-1);
	}

	if(!qvm_get_struct(file, qvm))
		err("[!] Error retrieving QVM structure\n");

	if(qvm->hdr.magic != QVM_MAGIC)
		err("[!] Wrong QVM signature\n");

	printf("/*\n *");
	w_bgreen(" filename:");
	printf(" %s\n *", qvm->filename);
	w_bgreen(" filesize:");
	printf(" 0x%x\n *", qvm->filesize);
	w_bgreen(" instruction count:");
	printf(" 0x%x\n *", qvm->hdr.instr_count);
	w_bgreen(" text offset:");
	printf(" 0x%x\n *", qvm->hdr.text_offset);
	w_bgreen(" text size:");
	printf(" 0x%x\n *", qvm->hdr.text_size);
	w_bgreen(" data offset:");
	printf(" 0x%x\n *", qvm->hdr.data_offset);
	w_bgreen(" data size:");
	printf(" 0x%x\n *", qvm->hdr.data_size);
	w_bgreen(" bss size:");
	printf(" 0x%x\n *", qvm->hdr.bss_size);
	w_bgreen(" LIT size:");
	printf(" 0x%x\n */\n\n", qvm->hdr.lit_size);

	if(!qvm_disasm(qvm, listing))
		err("[!] Error while disassembling\n");

	for(i = 0; *listing[i]; i++)
		printf("%s\n", listing[i]);

	free(qvm);
}

void err(char *error)
{
	w_bred(error);

	if(qvm->fd)
		fclose(qvm->fd);

	exit(-1);
}
