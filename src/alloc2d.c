#include <stdlib.h>

size_t rup2( size_t n, size_t multiple ) {
  return (n + multiple - 1) & ~(multiple - 1);
}

#include "alloc2d.d/alloc2d.h"

///////////////////////////////////////////////////////////////////////////////

int main() {
  double **const a2d = (double**)
    alloc2d( sizeof(double), alignof(double), 3, 2 );
  a2d[0][0] = 3.14;
  free( a2d );
}
