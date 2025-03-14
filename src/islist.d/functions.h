[[nodiscard]]
struct islist* islist_push( struct islist *head,
                            size_t size ) {
  struct islist *const new_head =
    malloc( sizeof(struct islist) + size );
  new_head->next = head;
  return new_head;
}

[[nodiscard]] void* islist_peek( struct islist *head ) {
  return head != nullptr ? head->data : nullptr;
}

void islist_pop( struct islist **phead ) {
  auto const head = *phead;
  if ( head == nullptr )
    return;
  *phead = head->next;
  free( head );
}
