void fl_print_error( char const *file, int line,
                     char const *format, ... ) {
  fprintf( stderr, "error: " );
  if ( opt_cdecl_debug != CDECL_DEBUG_NO )
    fprintf( stderr, "[%s:%d] ", file, line );
  va_list args;
  va_start( args );
  vfprintf( stderr, format, args );
  va_end( args );
}

#define print_error(FILE,LINE,FORMAT,...) \
  fl_print_error(__FILE__, __LINE__, (FORMAT), __VA_ARGS__)
