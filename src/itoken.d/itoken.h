struct itoken {         // fat pointer
  struct token_vtbl const *vptr;
  struct token *token;
};

void token_print( struct itoken const *it ) {
  auto const t = it->token;
  switch ( t->kind ) {
    case TOKEN_INT  : it->vptr->print_int  ( t->i ); break;
    case TOKEN_FLOAT: it->vptr->print_float( t->f ); break;
    case TOKEN_CHAR : it->vptr->print_char ( t->c ); break;
    case TOKEN_STR  : it->vptr->print_str  ( t->s ); break;
  }
}
