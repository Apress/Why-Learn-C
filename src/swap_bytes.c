#include <stdint.h>

#include "swap_bytes.d/swap_bytes.h"

////////// test functions /////////////////////////////////////////////////////

#include "unit_test.h"

int main( int argc, char const *const argv[] ) {
  test_prog_init( argc, argv );

  TEST( swap16( 0x0A'0B       ) ==       0x0B'0A );
  TEST( swap32( 0x0A'0B'0C'0D ) == 0x0D'0C'0B'0A );
}
