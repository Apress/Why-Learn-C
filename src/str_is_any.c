#include <string.h>

#include "str_is_any.d/str_is_any.h"

////////// test functions /////////////////////////////////////////////////////

#include "unit_test.h"

#define str_is_any(NEEDLE, ...) \
  str_is_any( (NEEDLE), (char const*[]){ __VA_ARGS__, nullptr } )

int main( int argc, char const *const argv[] ) {
  test_prog_init( argc, argv );

  TEST( !str_is_any( "x", "a", "b" ) );
  TEST(  str_is_any( "a", "a", "b" ) );
  TEST(  str_is_any( "b", "a", "b" ) );
}
