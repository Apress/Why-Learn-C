#include "config.h"                     /* must go first */

#include <stdio.h>
#include <stdlib.h>

[[noreturn]] static void perror_exit( char const *prog_name ) {
  perror( prog_name );
  exit( 2 );
}

[[noreturn]] static void usage( char const *prog_name ) {
  fprintf( stderr, "usage: %s path\n", prog_name );
  exit( 1 );
}

#include "stat.d/stat.h"
