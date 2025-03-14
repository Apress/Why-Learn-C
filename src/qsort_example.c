#include <stdlib.h>
#include <string.h>

static char const *COLORS[] = { "black", "white", "blue", "green", "red" };

#include "qsort_example.d/qsort_example.h"

////////// test functions /////////////////////////////////////////////////////

#include "unit_test.h"

int main( int argc, char const *const argv[] ) {
  test_prog_init( argc, argv );
  sort_colors();
  TEST( strcmp( COLORS[0], "black" ) == 0 );
  TEST( strcmp( COLORS[1], "blue"  ) == 0 );
  TEST( strcmp( COLORS[2], "green" ) == 0 );
  TEST( strcmp( COLORS[3], "red"   ) == 0 );
  TEST( strcmp( COLORS[4], "white" ) == 0 );
}
