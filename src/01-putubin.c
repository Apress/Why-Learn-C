#include "config.h"                     /* must go first */

#include "putubin.d/putubin.h"

///////////////////////////////////////////////////////////////////////////////

int main() {
  for ( unsigned i = 0; i < 10; ++i ) {
    unsigned const digits = putubin( i );
    printf( " %u\n", digits );
  }
}
