struct token_fn_tbl {
  void (*print_int)( long );
  void (*print_float)( double );
  void (*print_char)( char );
  void (*print_str)( char const* );
};

struct token {
  enum token_kind kind;
  union {
    int     i;
    double  f;
    char    c;
    char   *s;
  };
  // ...
  struct token_fn_tbl const *fn_tbl;
};

static struct token_fn_tbl const TOKEN_FN_TABLE_DEFAULT = {
  &print_int, &print_float, &print_char, &print_str
};

void token_print( struct token const *t ) {
  switch ( t->kind ) {
    case TOKEN_INT:
      t->fn_tbl->print_int( t->i );
      break;
    case TOKEN_FLOAT:
      t->fn_tbl->print_float( t->f );
      break;
    case TOKEN_CHAR:
      t->fn_tbl->print_char( t->c );
      break;
    case TOKEN_STR:
      t->fn_tbl->print_str( t->s );
      break;
  }
}
