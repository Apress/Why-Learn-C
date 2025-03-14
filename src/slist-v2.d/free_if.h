typedef bool (*slist_pred_fn)( struct slink *link,
                               void const *pred_data );

size_t slist_free_if( struct slist *list,
                      slist_pred_fn pred_fn,
                      void const *pred_data ) {
  size_t free_count = 0;
  struct slink **pcurr = &list->head, *prev = nullptr;

  for (;;) {
    auto const curr = *pcurr;
    if ( curr == nullptr )
      break;
    if ( !(*pred_fn)( curr, pred_data ) ) {
      prev = curr;
      pcurr = &curr->next;
      continue;
    }
    if ( curr == list->tail )
      list->tail = prev;
    *pcurr = curr->next;
    free( curr );
    ++free_count;
  }

  return free_count;
}
