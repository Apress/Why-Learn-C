bool slist_free_if_not_contains_str( struct slink *link,
       void const *pred_data ) {
  return strstr( SLIST_DINT( link->data ),
                 pred_data ) == nullptr;
}
