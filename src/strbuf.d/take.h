[[nodiscard]] char* strbuf_take( struct strbuf *sbuf ) {
  auto const contents = sbuf->contents;
  *sbuf = (struct strbuf){ };
  return contents;
}
