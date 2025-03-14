void slist_push_mtx( struct slist **phead, void *data,
                     mtx_t *mtx ) {
  struct slist *const new_head =
    malloc( sizeof(struct slist) );
  new_head->data = data;
  mtx_lock( mtx );
  new_head->next = *phead;
  *phead = new_head;
  mtx_unlock( mtx );
}

[[nodiscard]] void* slist_peek_mtx( struct slist *head,
                                    mtx_t *mtx ) {
  mtx_lock( mtx );
  auto *const data = head != nullptr ?
    head->data : nullptr;
  mtx_unlock( mtx );
  return data;
}

[[nodiscard]] void* slist_pop_mtx( struct slist **phead,
                                   mtx_t *mtx ) {
  mtx_lock( mtx );
  auto const head = *phead;
  if ( head == nullptr ) {
    mtx_unlock( mtx );
    return nullptr;
  }
  *phead = head->next;
  mtx_unlock( mtx );
  auto const data = head->data;
  free( head );
  return data;
}
