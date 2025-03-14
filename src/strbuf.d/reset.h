void strbuf_reset( struct strbuf *sbuf ) {
  if ( sbuf->contents != nullptr )
    sbuf->contents[0] = '\0';
  sbuf->len = 0;
}
