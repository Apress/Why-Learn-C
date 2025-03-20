#include "config.h"                     /* must go first */

#include <stdarg.h>
#include <string.h>

#include "vstr_is_any.d/vstr_is_any.h"

////////// test functions /////////////////////////////////////////////////////

#include "unit_test.h"

#define vstr_is_any(NEEDLE, ...)  vstr_is_any( (NEEDLE), __VA_ARGS__, nullptr )

int main( int argc, char const *const argv[] ) {
  test_prog_init( argc, argv );

  TEST( !vstr_is_any( "x", "a", "b" ) );
  TEST(  vstr_is_any( "a", "a", "b" ) );
  TEST(  vstr_is_any( "b", "a", "b" ) );
}
