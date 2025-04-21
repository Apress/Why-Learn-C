#include "config.h"                     /* must go first */

#include <stdlib.h>
#include <string.h>

#include "c23_strtol.d/c23_strtol.h"

////////// test functions /////////////////////////////////////////////////////

#include "unit_test.h"

int main( int argc, char const *const argv[] ) {
  test_prog_init( argc, argv );

  TEST( c23_strtol(      "123", nullptr, 10 ) == 123 );
  TEST( c23_strtol(     " 123", nullptr, 10 ) == 123 );
  TEST( c23_strtol(     "-123", nullptr, 10 ) == -123 );
  TEST( c23_strtol(    " -123", nullptr, 10 ) == -123 );

  TEST( c23_strtol( "0b101010", nullptr,  0 ) ==  42 );
  TEST( c23_strtol( "0B101010", nullptr,  0 ) ==  42 );

  TEST( c23_strtol(   "101010", nullptr,  2 ) ==  42 );
  TEST( c23_strtol(  "-101010", nullptr,  2 ) == -42 );
  TEST( c23_strtol( " -101010", nullptr,  2 ) == -42 );
  TEST( c23_strtol( "0b101010", nullptr,  2 ) ==  42 );
  TEST( c23_strtol( "0B101010", nullptr,  2 ) ==  42 );
}
