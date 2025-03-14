[[nodiscard]]
struct slink* slist_push_back( struct slist *list,
                               size_t size ) {
  struct slink *const link =
    malloc( sizeof(struct slink) + size );
  if ( list->head == nullptr )
    list->head = link;
  else
    list->tail->next = link;
  list->tail = link;
  return link;
}

[[nodiscard]]
struct slink* slist_push_front( struct slist *list,
                                size_t size ) {
  struct slink *const link =
    malloc( sizeof(struct slink) + size );
  link->next = list->head;
  list->head = link;
  if ( list->tail == nullptr )
    list->tail = link;
  return link;
}
