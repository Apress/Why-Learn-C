int main( int argc, char const *const argv[] ) {
  if ( --argc > 2 )
    usage( argv[0] );

  char    buf[ BUF_SIZE ];
  size_t  bytes;
  FILE   *fin = stdin, *fout = stdout;

  if ( argc > 0 ) {
    fin = check_open( argv[1], "r" );
    if ( argc > 1 )
      fout = check_open( argv[2], "w" );
  }

  errno = 0;
  do {
    bytes = fread( buf, 1, BUF_SIZE, fin );
    if ( ferror( fin ) )
      break;
    if ( fwrite( buf, 1, bytes, fout ) < bytes )
      break;
  } while ( bytes == BUF_SIZE );

  fclose( fin );
  fclose( fout );
  if ( errno != 0 )
    perror_exit();
}
