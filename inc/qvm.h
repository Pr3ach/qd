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

#if !defined(QVM_H)
#define QVM_H

#include <stdint.h>

#define QVM_MAGIC 0x12721444
#define QVM_MAX_LISTING 0xffffff

typedef struct qvm_hdr_t{
	uint32_t magic;
	uint32_t instr_count;
	uint32_t text_offset;
	uint32_t text_size;
	uint32_t data_offset;
	uint32_t data_size;
	uint32_t lit_size;
	uint32_t bss_size;
} qvm_hdr_t;

typedef struct qvm_t{
	char *filename;
	FILE *fd;
	uint32_t filesize;
	qvm_hdr_t hdr;
} qvm_t;

typedef struct qvm_opcode_t{
	uint8_t op;
	uint8_t arg_size;
	char mnemonic[16];
} qvm_opcode_t;

int qvm_get_struct(char *file, qvm_t *qvm);
int qvm_disasm(qvm_t *qvm, char out[QVM_MAX_LISTING][64]);

#endif /* !QVM_H */
