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

#if !defined(QD_H)
#define QD_H

#include "qvm.h"

#define VERSION "1.0"

#if defined(__linux__) || (defined(__APPLE__) && defined(__MACH__)) || defined(__unix__)
#define PLATFORM "unix"
#else
#define PLATFORM "win32"
#endif

qvm_t *qvm;
char listing[QVM_MAX_LISTING][64];

void disasm(char *file);
void err(char *error);

#endif /* !QD_H */
