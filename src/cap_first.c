// Answer to chapter 2, exercise 1.

#include <ctype.h>
#include <stdio.h>
#include <string.h>

constexpr char CAP_NEXT_CHARS[] = " \n\t([{";

int main() {
  bool cap_next = true;
  for ( int c; (c = getchar()) != EOF; ) {
    if ( cap_next )
      c = toupper( c );
    putchar( c );
    cap_next = strchr( CAP_NEXT_CHARS, c ) != nullptr;
  }
}
