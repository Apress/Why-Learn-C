#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>           // for exit()

static jmp_buf env;

void read_file( char const *path ) {
  FILE *f = fopen( path, "r" );
  if ( f == nullptr )
    longjmp( env, 1 );        // "throw"
  // ...
}

void load_config() {
  // ...
  read_file( ".config" );
  // ...
}

int main() {
  if ( setjmp( env ) == 0 ) { // "try"
    load_config();
  } else {                    // "catch"
    fprintf( stderr, "error loading configuration\n" );
    exit( EXIT_FAILURE );
  }
}
