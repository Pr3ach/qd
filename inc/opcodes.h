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

#if !defined(OPCODES_H)
#define OPCODES_H

#include "qvm.h"

qvm_opcode_t opcodes[0x100] = {
	{0x00, 0, "UNDEF"},
	{0x01, 0,"IGNORE"},
	{0x02, 0, "BREAK"},
	{0x03, 4, "ENTER"},
	{0x04, 4, "LEAVE"},
	{0x05, 0, "CALL"},
	{0x06, 0, "PUSH"},
	{0x07, 0, "POP"},
	{0x08, 4, "CONST"},
	{0x09, 4, "LOCAL"},
	{0x0a, 0, "JUMP"},
	{0x0b, 4, "EQ"},
	{0x0c, 4, "NE"},
	{0x0d, 4, "LTI"},
	{0x0e, 4, "LEI"},
	{0x0f, 4, "GTI"},
	{0x10, 4, "GEI"},
	{0x11, 4, "LTU"},
	{0x12, 4, "LEU"},
	{0x13, 4, "GTU"},
	{0x14, 4, "GEU"},
	{0x15, 4, "EQF"},
	{0x16, 4, "NEF"},
	{0x17, 4, "LTF"},
	{0x18, 4, "LEF"},
	{0x19, 4, "GTF"},
	{0x1a, 4, "GEF"},
	{0x1b, 0, "LOAD1"},
	{0x1c, 0, "LOAD2"},
	{0x1d, 0, "LOAD4"},
	{0x1e, 0, "STORE1"},
	{0x1f, 0, "STORE2"},
	{0x20, 0, "STORE4"},
	{0x21, 1, "ARG"},
	{0x22, 4, "BLOCK_COPY"}, /* operand size is 4, not 0 as icculus page says; checkout @code/qcommon/vm_interpreted.c */
	{0x23, 0, "SEX8"},
	{0x24, 0, "SEX16"},
	{0x25, 0, "NEGI"},
	{0x26, 0, "ADD"},
	{0x27, 0, "SUB"},
	{0x28, 0, "DIVI"},
	{0x29, 0, "DIVU"},
	{0x2a, 0, "MODI"},
	{0x2b, 0, "MODU"},
	{0x2c, 0, "MULI"},
	{0x2d, 0, "MULU"},
	{0x2e, 0, "BAND"},
	{0x2f, 0, "BOR"},
	{0x30, 0, "BXOR"},
	{0x31, 0, "BCOM"},
	{0x32, 0, "LSH"},
	{0x33, 0, "RSHI"},
	{0x34, 0, "RSHU"},
	{0x35, 0, "NEGF"},
	{0x36, 0, "ADDF"},
	{0x37, 0, "SUBF"},
	{0x38, 0, "DIVF"},
	{0x39, 0, "MULF"},
	{0x3a, 0, "CVIF"},
	{0x3b, 0, "CVFI"},
	[0x3c ... 0xff] = {0, 0, "UNDEF"}
};

#endif /* !OPCODES_H */
