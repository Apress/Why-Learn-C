void token_cpy( struct token *dst,
                struct token const *src ) {
  if ( dst == src )
    return;
  if ( dst->kind == TOKEN_STR )
    free( dst->s );
  if ( src->kind == TOKEN_STR ) {
    *dst = (struct token){
      .kind = TOKEN_STR, .s = strdup( src->s )
    };
  } else {
    memcpy( dst, src, sizeof *dst );
  }
}
