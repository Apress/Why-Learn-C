[[noreturn]] static void usage( char const *prog ) {
  fprintf( stderr,
           "usage: %s [infile [outfile]]\n", prog );
  exit( 1 );
}
