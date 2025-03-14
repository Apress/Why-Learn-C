struct token {
  enum token_kind kind;
  union {
    int     i;
    double  f;
    char    c;
    char   *s;
  };
  // ...
  void (*print_int)( long );
  void (*print_float)( double );
  void (*print_char)( char );
  void (*print_str)( char const* );
};

void token_print( struct token const *t ) {
  switch ( t->kind ) {
    case TOKEN_INT  : t->print_int  ( t->i ); break;
    case TOKEN_FLOAT: t->print_float( t->f ); break;
    case TOKEN_CHAR : t->print_char ( t->c ); break;
    case TOKEN_STR  : t->print_str  ( t->s ); break;
  }
}
