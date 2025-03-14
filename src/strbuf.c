#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma clang diagnostic ignored "-Wformat-nonliteral"

#include "strbuf.d/struct.h"
#include "strbuf.d/cleanup.h"
#include "strbuf.d/reserve.h"
#include "strbuf.d/puts.h"
#include "strbuf.d/printf.h"
#include "strbuf.d/reset.h"
#include "strbuf.d/take.h"
#include "strbuf.d/str_list.h"

extern inline void strbuf_puts( struct strbuf *sbuf, char const *s );
extern inline void strbuf_putc( struct strbuf *sbuf, char c );

////////// test functions /////////////////////////////////////////////////////

#include "unit_test.h"

#define STR_LIST(...)   (char const*[]){ __VA_ARGS__ __VA_OPT__(,) nullptr }

int main( int argc, char const *const argv[] ) {
  test_prog_init( argc, argv );
  TEST( strcmp( str_list( STR_LIST() ), "" ) == 0 );
  TEST( strcmp( str_list( STR_LIST( "a" ) ), "a" ) == 0 );
  TEST( strcmp( str_list( STR_LIST( "a", "b" ) ), "a or b" ) == 0 );
  TEST( strcmp( str_list( STR_LIST( "a", "b", "c" ) ), "a, b, or c" ) == 0 );
}
