/*
**      "Why Learn C"
**      unit_test.c
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
#include "unit_test.h"

// standard
#include <stdio.h>
#include <stdlib.h>
#include <sysexits.h>

///////////////////////////////////////////////////////////////////////////////

// extern variables
unsigned test_failures;

////////// local functions ////////////////////////////////////////////////////

_Noreturn
static void test_prog_exit( void ) {
  printf( "%u failures\n", test_failures );
  _Exit( test_failures > 0 ? EX_SOFTWARE : EX_OK );
}

_Noreturn
static void test_prog_usage( void ) {
  fprintf( stderr, "usage: %s\n", prog_name );
  exit( EX_USAGE );
}

////////// extern functions ///////////////////////////////////////////////////

void test_prog_init( int argc, char const *const argv[] ) {
  prog_name = argv[0];
  if ( --argc != 0 )
    test_prog_usage();
  atexit( &test_prog_exit );
}

///////////////////////////////////////////////////////////////////////////////
/* vim:set et sw=2 ts=2: */
