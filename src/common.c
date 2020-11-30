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
#include <string.h>
#include <stdarg.h>
#include "../inc/common.h"
#include "../color_shell/color_shell.h"

char raw_buf[MAX_RAW_BUF];

char *raw(char *fmt, ...)
{
	char buf[MAX_RAW_BUF];
	va_list ap;

	va_start(ap, fmt);
	vsnprintf(buf, MAX_RAW_BUF - 1, fmt, ap);
	va_end(ap);

	memset(raw_buf, 0, MAX_RAW_BUF);

	return strncpy(raw_buf, buf, MAX_RAW_BUF);
}
