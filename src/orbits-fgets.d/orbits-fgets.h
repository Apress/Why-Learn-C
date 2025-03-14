double parse_double( char const **ps,
                     char const *term_chars ) {
  char *end;
  errno = 0;
  auto const n = strtod( *ps, &end );
  if ( errno == ERANGE ) {
    fprintf( stderr, "\"%s\": value out of range\n", *ps );
    exit( 3 );
  }
  if ( strchr( term_chars, *end ) == nullptr ) {
    fprintf( stderr, "'%c': invalid character\n", *end );
    exit( 4 );
  }
  *ps = *end == '\0' ? end : end + 1;
  return n;
}

void read_planet_data( FILE *f ) {
  char line[128];
  for ( unsigned p = 0; p < 8; ++p ) {
    char const *s = fgets( line, sizeof line, f );
    if ( s == nullptr ) {
      if ( ferror( f ) ) {
        perror( "orbits" );
        exit( 2 );
      }
      break;
    }
    PLANET[p].perihelion_au = parse_double( &s, ",\n" );
    PLANET[p].aphelion_au   = parse_double( &s, ",\n" );
  }
}
