void swapi( int *pa, int *pb ) {  // v3 -- with const
  const int temp = *pa;           // temp won't change
  *pa = *pb;
  *pb = temp;
}

///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>

int main() {
  int x = 1, y = 2;
  swapi( &x, &y );
  printf( "x=%d, y=%d\n", x, y );
}
