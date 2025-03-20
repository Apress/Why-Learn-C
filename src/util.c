/*
**      "Why Learn C"
**      util.c
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

// local
#include "config.h"                     /* must go first */
#include "util.h"

// standard
#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////////////////

// extern variables
char const *prog_name;

////////// extern functions ///////////////////////////////////////////////////

void perror_exit( int status ) {
  perror( prog_name );
  exit( status );
}

///////////////////////////////////////////////////////////////////////////////
/* vim:set et sw=2 ts=2: */
