#include <stdio.h>

unsigned putubin( unsigned n ) {
  if ( n == 0 ) {
    putchar( '0' );
    return 1;
  }
  unsigned digits = 0;
  for ( unsigned bit = ~(~0u >> 1); bit != 0; bit >>= 1 ) {
    bool const is_1 = (n & bit) != 0;
    if ( is_1 || digits > 0 ) {
      putchar( '0' + is_1 );
      ++digits;
    }
  }
  return digits;
}
