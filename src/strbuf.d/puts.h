void strbuf_putsn( struct strbuf *sbuf, char const *s,
                   size_t n ) {
  n = strnlen( s, n );
  strbuf_reserve( sbuf, n );
  memcpy( sbuf->contents + sbuf->len, s, n );
  sbuf->len += n;
  sbuf->contents[ sbuf->len ] = '\0';
}

inline void strbuf_puts( struct strbuf *sbuf,
                         char const *s ) {
  strbuf_putsn( sbuf, s, strlen( s ) );
}

inline void strbuf_putc( struct strbuf *sbuf, char c ) {
  strbuf_putsn( sbuf, &c, 1 );
}
