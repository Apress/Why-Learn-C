static FILE* check_open( char const *path,
                         char const *mode ) {
  FILE *const f = fopen( path, mode );
  if ( f == nullptr )
    perror_exit();
  return f;
}
