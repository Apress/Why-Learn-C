bool slist_free_if_dup_str( struct slink *link,
                            void const* ) {
  return link->next != nullptr &&
         strcmp( SLIST_DINT( link->data ),
                 SLIST_DINT( link->next->data ) ) == 0;
}
