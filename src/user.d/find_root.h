bool user_name_equal( struct user const *i_user,
                      struct user const *j_user ) {
  return user_cmp( i_user, j_user ) == 0;
}

struct user* find_root( struct slist *user_list ) {
  struct slist *found = slist_find( user_list,
                        (slist_pred_fn)&user_name_equal,
                        &(struct user){ .last = "root" } );
  // ...
  return found->data;
}
