#include <stdarg.h>

int vnsum( unsigned n, ... ) {
  va_list args;
  va_start( args );
  int sum = 0;
  while ( n-- > 0 )
    sum += va_arg( args, int );
  va_end( args );
  return sum;
}

////////// test functions /////////////////////////////////////////////////////

#include "unit_test.h"

int main( int argc, char const *const argv[] ) {
  test_prog_init( argc, argv );

  TEST( vnsum( 0 ) == 0 );
  TEST( vnsum( 1, 42 ) == 42 );
  TEST( vnsum( 2, 1, 2 ) == 3 );
}
