/*
**      "Why Learn C"
**      util.h
**
**      Copyright (C) 2025  Paul J. Lucas
**
**      This program is free software: you can redistribute it and/or modify
**      it under the terms of the GNU General Public License as published by
**      the Free Software Foundation, either version 3 of the License, or
**      (at your option) any later version.
**
**      This program is distributed in the hope that it will be useful,
**      but WITHOUT ANY WARRANTY; without even the implied warranty of
**      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**      GNU General Public License for more details.
**
**      You should have received a copy of the GNU General Public License
**      along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef wlc_util_H
#define wlc_util_H

///////////////////////////////////////////////////////////////////////////////

// extern variables
extern char const  *prog_name;          ///< Program name.

/**
 * Prints an error message for `errno` to standard error and exits.
 *
 * @param status The exit status code.
 */
[[noreturn]] void perror_exit( int status );

///////////////////////////////////////////////////////////////////////////////

#endif /* wlc_util_H */
/* vim:set et sw=2 ts=2: */
