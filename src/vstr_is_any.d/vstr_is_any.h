bool vstr_is_any( char const *needle, ... ) {
  va_list args;
  va_start( args );
  bool found = false;
  do {
    char const *const hay = va_arg( args, char* );
    if ( hay == nullptr )
      break;
    found = strcmp( needle, hay ) == 0;
  } while ( !found );
  va_end( args );
  return found;
}
