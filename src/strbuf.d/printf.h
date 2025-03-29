int strbuf_printf( struct strbuf *sbuf,
                   char const *format, ... ) {
  char *buf = sbuf->contents == nullptr ?
    nullptr : sbuf->contents + sbuf->len;

  va_list args;
  va_start( args );
  auto raw_len =
    vsnprintf( buf, sbuf->cap - sbuf->len, format, args );
  va_end( args );
  if ( raw_len <= 0 )
    return raw_len;

  auto const args_len = (size_t)raw_len;
  if ( strbuf_reserve( sbuf, args_len ) ) {
    buf = sbuf->contents + sbuf->len;
    va_start( args );
    raw_len = vsnprintf( buf, args_len + 1, format, args );
    va_end( args );
    assert( raw_len > 0 );
  }

  sbuf->len += args_len;
  return raw_len;
}
