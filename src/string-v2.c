#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma clang diagnostic ignored "-Wformat-nonliteral"

#include "string-v2.d/struct.h"
#include "string-v2.d/printf.h"
#include "string-v2.d/putsn.h"
#include "string-v2.d/puts_putc.h"
#include "string-v2.d/take.h"

extern void string_puts( struct string*, char const* );
extern void string_putc( struct string*, char );

////////// test functions /////////////////////////////////////////////////////

#include "unit_test.h"

int main( int argc, char const *const argv[] ) {
  test_prog_init( argc, argv );

  struct string s = { };
  string_puts( &s, "hello" );
  string_printf( &s, ", %s", "world" );

  TEST( s.len == 12 );
  TEST( strcmp( s.contents, "hello, world" ) == 0 );
}
