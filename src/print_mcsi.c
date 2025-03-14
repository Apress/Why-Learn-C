#include <stdio.h>

#include "print_mcsi.d/print_mcsi.h"

///////////////////////////////////////////////////////////////////////////////

int main() {
  constexpr int m[2][3] = {
    { 11, 12, 13 },
    { 21, 22, 23 },
  };
  print_mcsi( 2, 3, m );
}
