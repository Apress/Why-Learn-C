typedef bool (*slist_pred_fn)( void const *list_data,
                               void const *pred_data );

struct slist* slist_find( struct slist *list,
                          slist_pred_fn pred_fn,
                          void const *pred_data ) {
  while ( list != nullptr &&
          !(*pred_fn)( list->data, pred_data ) ) {
    list = list->next;
  }
  return list;
}
