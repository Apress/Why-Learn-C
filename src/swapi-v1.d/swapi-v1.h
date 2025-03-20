#include <stdio.h>

void swapi( int a, int b ) {      // v1 -- WRONG
  int temp = a;
  a = b;
  b = temp;
}

int main() {
  int x = 1, y = 2;
  swapi( x, y );
  printf( "x=%d, y=%d\n", x, y ); // prints: x=1, y=2
}
