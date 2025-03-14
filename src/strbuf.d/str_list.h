[[nodiscard]]
char const* str_list( char const *list[static 1] ) {
  if ( list[0] == nullptr )
    return "";

  static struct strbuf sbuf;
  strbuf_reset( &sbuf );
  strbuf_puts( &sbuf, list[0] );

  for ( unsigned i = 1; list[i] != nullptr; ++i ) {
    auto const sep = list[i+1] != nullptr ?
      ", " : i > 1 ? ", or " : " or ";
    strbuf_printf( &sbuf, "%s%s", sep, list[i] );
  }

  return sbuf.contents;
}
