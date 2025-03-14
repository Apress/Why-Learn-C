#include <stdio.h>

#include "print_hist.d/print_hist.h"
#include "handy/ARRAY_SIZE.h"

///////////////////////////////////////////////////////////////////////////////

int main() {
  static constexpr unsigned VALS[] = {
    1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5
  };
  print_hist( ARRAY_SIZE( VALS ), VALS, 5, '+' );
}
