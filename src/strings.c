#include <ctype.h>
#include <stdio.h>

constexpr size_t STRING_MIN = 4;

int main() {
  int     c;
  char    str_buf[ STRING_MIN ] = { };
  size_t  str_len = 0;

  while ( (c = getchar()) != EOF ) {
    if ( isprint( c ) ) {
      if ( str_len < STRING_MIN - 1 ) {
        str_buf[ str_len++ ] = (char)c;
        continue;
      }
      if ( str_len == STRING_MIN - 1 ) {
        str_buf[ str_len++ ] = '\0';
        fputs( str_buf, stdout );
      }
      putchar( c );
    }
    else {
      if ( str_len == STRING_MIN )
        putchar( '\n' );
      str_len = 0;
    }
  } // while
}
