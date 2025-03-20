#include <stdio.h>

constexpr unsigned TAB_STOP = 8;  // chars per tab-stop

int main() {
  unsigned len = 0;               // length of line so far
  while ( true ) {
    int const c = getchar();
    switch ( c ) {
      case EOF:
        return 0;
      case '\t':
        unsigned const spaces = TAB_STOP - len % TAB_STOP;
        printf( "%*s", spaces, "" );
        len += spaces;
        continue;
      case '\n':
        len = 0;
        break;
      default:
        ++len;
    }
    putchar( c );
  }
}
