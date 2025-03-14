#include <stdio.h>

/*
   Copy input to output, v1.
 */
int main() {
  int c;                // declare variable 'c' as int
  c = getchar();        // get char. from "standard input"
  while ( c != EOF ) {  // while it's not end-of-file ...
    putchar( c );       //   print it to "standard output"
    c = getchar();      //   read the next character
  }                     //   and repeat
}
