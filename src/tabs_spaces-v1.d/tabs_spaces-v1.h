#include <stdio.h>

constexpr unsigned TAB_STOP = 8;  // chars per tab-stop

int main() {
  unsigned len = 0;               // length of line so far
  for ( int c; (c = getchar()) != EOF; ) {
    if ( c == '\t' ) {
      unsigned const spaces = TAB_STOP - len % TAB_STOP;
      printf( "%*s", spaces, "" );
      len += spaces;
      continue;
    }
    putchar( c );
    if ( c == '\n' )
      len = 0;
    else
      ++len;
  }
}
