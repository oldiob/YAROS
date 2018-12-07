/*
 * Copyright (C) Olivier Dion <olivier.dion@polymtl.ca>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TYPE_H
#define TYPE_H

#include <stdint.h>

#include "YAROS/config.h"


/* Unsigned */
typedef uint8_t U8;
typedef uint16_t U16;
typedef uint32_t U32;
typedef uint64_t U64;

/* Signed */
typedef int8_t S8;
typedef int16_t S16;
typedef int32_t S32;
typedef int64_t S64;

/* Size for Array; Signed */
typedef long ssize_t;

/* Size for Stack */
typedef STACK_SIZE_TYPE sstack_t;

/* Jiffy */
typedef JIFFY_TYPE jiffy_t;

/* Task function */
typedef void (*taskfunc) (void *);

/* Boolean */
#define false 0
#define true 1
typedef unsigned char bool;

#endif /* TYPE_H */
