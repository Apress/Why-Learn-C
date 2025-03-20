#include <stdio.h>
#include <stdlib.h>             // for malloc & free
#include <string.h>

char* mstrcat( char const *s1, char const *s2 ) {
  size_t const s1_len = strlen( s1 );
  char *const s12 = malloc( s1_len + strlen( s2 ) + 1 );
  strcpy( s12, s1 );
  strcpy( s12 + s1_len, s2 );
  return s12;
}

int main() {
  char *const msg = mstrcat( "hello", ", world" );
  puts( msg );
  free( msg );
}
