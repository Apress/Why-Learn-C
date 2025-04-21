#include "config.h"                     /* must go first */

#include "vnsum.d/vnsum.h"

////////// test functions /////////////////////////////////////////////////////

#include "unit_test.h"

int main( int argc, char const *const argv[] ) {
  test_prog_init( argc, argv );

  TEST( vnsum( 0 ) == 0 );
  TEST( vnsum( 1, 42 ) == 42 );
  TEST( vnsum( 2, 1, 2 ) == 3 );
}
