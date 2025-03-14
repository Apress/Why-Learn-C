struct user {
  char           *last;
  char            mi;
  char           *first;
  unsigned short  uid;
};

int user_cmp( struct user const *u1,
              struct user const *u2 ) {
  int cmp;
  if ( (cmp = strcmp( u1->last, u2->last )) != 0 )
    return cmp;
  if ( (cmp = strcmp( u1->first, u2->first )) != 0 )
    return cmp;
  return (int)u1->mi - (int)u2->mi;
}
