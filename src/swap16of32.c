#include <stdint.h>

#include "swap16of32.d/swap16of32.h"

////////// test functions /////////////////////////////////////////////////////

#include "unit_test.h"

int main( int argc, char const *const argv[] ) {
  test_prog_init( argc, argv );

  TEST( swap16of32( 0x0102'0304 ) == 0x0304'0102 );
}
