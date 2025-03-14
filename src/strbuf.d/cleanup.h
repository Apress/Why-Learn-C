void strbuf_cleanup( struct strbuf *sbuf ) {
  free( sbuf->contents );
  *sbuf = (struct strbuf){ };
}
