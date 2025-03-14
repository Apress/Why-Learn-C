inline struct slist const*
const_slist_find( struct slist const *list,
                  slist_pred_fn pred_fn,
                  void const *pred_data ) {
  return slist_find( (struct slist*)list, pred_fn,
                     pred_data );
}
