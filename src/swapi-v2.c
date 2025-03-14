#include <stdio.h>

void swapi( int *pa, int *pb ) {  // v2 -- correct
  int temp = *pa;
  *pa = *pb;
  *pb = temp;
}

int main() {
  int x = 1, y = 2;
  swapi( &x, &y );                // note '&'
  printf( "x=%d, y=%d\n", x, y ); // prints: x=2, y=1
}
