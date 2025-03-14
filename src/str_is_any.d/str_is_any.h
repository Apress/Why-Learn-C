bool str_is_any( char const *needle,
                 char const *const haystack[] ) {
  for ( unsigned i = 0; haystack[i] != nullptr; ++i ) {
    if ( strcmp( needle, haystack[i] ) == 0 )
      return true;
  }
  return false;
}
