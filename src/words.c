#include "config.h"                     /* must go first */

// Answer to chapter 5, exercise 1.

#include <ctype.h>
#include <stdio.h>

int main() {
  int c;
  bool in_word = false;
  do {
    c = getchar();
    if ( isalnum( c ) ) {
      in_word = true;
      putchar( c );
    } else if ( in_word ) {
      putchar( '\n' );
      in_word = false;
    }
  } while ( c != EOF );
}
