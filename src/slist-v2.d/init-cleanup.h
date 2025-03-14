typedef void (*slist_free_fn)( void *data );

inline void slist_init( struct slist *list ) {
  *list = (struct slist){ };
}

void slist_cleanup( struct slist *list,
                    slist_free_fn free_fn ) {
  if ( list == nullptr )
    return;
  struct slink *curr = list->head, *next;
  if ( free_fn == nullptr ) {
    for ( ; curr != nullptr; curr = next ) {
      next = curr->next;
      free( curr );
    }
  } else {
    for ( ; curr != nullptr; curr = next ) {
      (*free_fn)( curr->data );
      next = curr->next;
      free( curr );
    }
  }
  slist_init( list );
}
