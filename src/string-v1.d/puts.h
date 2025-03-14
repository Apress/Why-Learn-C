void string_puts( struct string *str, char const *s ) {
  size_t const new_len = str->len + strlen( s );
  str->contents = realloc( str->contents, new_len + 1 );
  strcpy( str->contents + str->len, s );
  str->len = new_len;
}
