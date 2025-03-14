void slist_pop_front( struct slist *list ) {
  if ( list->head == nullptr )
    return;
  auto const new_head = list->head->next;
  free( list->head );
  list->head = new_head;
  if ( list->head == nullptr )
    list->tail = nullptr;
}

void slist_pop_back( struct slist *list ) {
  if ( list->head == nullptr )
    return;
  auto new_tail = list->head;
  while ( new_tail->next != list->tail )
    new_tail = new_tail->next;
  free( list->tail );
  new_tail->next = nullptr;
  list->tail = new_tail;
}
