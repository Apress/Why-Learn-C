#include "config.h"                     /* must go first */

#include <stdio.h>

#include "swapi-v3.d/swapi-v3.h"

///////////////////////////////////////////////////////////////////////////////

int main() {
  int x = 1, y = 2;
  swapi( &x, &y );
  printf( "x=%d, y=%d\n", x, y );
}
