inline void string_puts( struct string *str,
                         char const *s ) {
  string_putsn( str, s, strlen( s ) );
}

inline void string_putc( struct string *str, char c ) {
  string_putsn( str, &c, 1 );
}
