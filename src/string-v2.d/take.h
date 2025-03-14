[[nodiscard]] char* string_take( struct string *str ) {
  auto const contents = str->contents;
  *str = (struct string){ };
  return contents;
}
