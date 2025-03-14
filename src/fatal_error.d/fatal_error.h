#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat-nonliteral"

[[noreturn]] void fatal_error( int status,
                               char const *format, ... ) {
  fprintf( stderr, "%s: ", prog_name );
  va_list args;
  va_start( args );
  vfprintf( stderr, format, args );
  va_end( args );
  exit( status );
}

#pragma GCC diagnostic pop
