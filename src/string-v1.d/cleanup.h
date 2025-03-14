void string_cleanup( struct string *str ) {
  free( str->contents );
  *str = (struct string){ };
}
