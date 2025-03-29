[[nodiscard]] struct slist* slist_push( struct slist *head,
                                        void *data ) {
  struct slist *const new_head =
    malloc( sizeof(struct slist) );
  new_head->next = head;
  new_head->data = data;
  return new_head;
}

[[nodiscard]] void* slist_peek( struct slist *head ) {
  return head != nullptr ? head->data : nullptr;
}

[[nodiscard]] void* slist_pop( struct slist **phead ) {
  auto const head = *phead;
  if ( head == nullptr )
    return nullptr;
  *phead = head->next;
  auto const data = head->data;
  free( head );
  return data;
}
