void read_file( char const *path ) {
  auto const f = fopen( path, "r" );
  if ( f == nullptr )
    throw ( EX_FILE_NOT_FOUND );
  try {
    // ... do something with f ...
  }
  finally {
    fclose( f );
  }
}
