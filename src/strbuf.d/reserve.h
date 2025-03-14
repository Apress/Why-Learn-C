bool strbuf_reserve( struct strbuf *sbuf,
                     size_t res_len ) {
  if ( res_len < sbuf->cap - sbuf->len )
    return false;
  if ( sbuf->cap == 0 )
    sbuf->cap = 2;
  auto const new_len = sbuf->len + res_len;
  while ( sbuf->cap <= new_len )
    sbuf->cap <<= 1;
  sbuf->contents = realloc( sbuf->contents, sbuf->cap );
  return true;
}
