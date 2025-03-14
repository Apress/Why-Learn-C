int string_printf( struct string *str,
                   char const *format, ... ) {
  va_list args;
  va_start( args );
  int raw_len = vsnprintf( nullptr, 0, format, args );
  va_end( args );
  if ( raw_len <= 0 )
    return raw_len;

  auto const args_len = (size_t)raw_len;
  auto const new_len = str->len + args_len;
  str->contents = realloc( str->contents, new_len + 1 );
  char *const buf = str->contents + str->len;

  va_start( args );
  raw_len = vsnprintf( buf, args_len + 1, format, args );
  va_end( args );
  str->len = new_len;
  return raw_len;
}
