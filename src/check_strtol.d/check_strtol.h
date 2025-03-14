long check_strtol( char const *s ) {
  char *end;
  errno = 0;
  auto const n = strtol( s, &end, 10 );
  if ( errno == EINVAL )
    fprintf( stderr, "\"%s\": invalid string\n", s );
  else if ( errno == ERANGE )
    fprintf( stderr, "\"%s\": range error\n", s );
  else if ( *end != '\0' )
    fprintf( stderr, "%s\n%*s^\n", s, (int)(end - s), "" );
  return n;
}
