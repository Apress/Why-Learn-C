void string_putsn( struct string *str, char const *s,
                   size_t n ) {
  n = strnlen( s, n );
  auto const new_len = str->len + n;
  str->contents = realloc( str->contents, new_len + 1 );
  memcpy( str->contents + str->len, s, n );
  str->len = new_len;
  str->contents[ str->len ] = '\0';
}
