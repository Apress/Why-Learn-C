struct ht_insert_rv ht_insert( struct hash_table *ht,
                               void const *key,
                               size_t data_size ) {
  auto const hash = (*ht->hash_fn)( key );
  auto const n_buckets = HT_PRIME[ ht->prime_idx ];
  auto const b = hash % n_buckets;
  struct ht_entry *const head = &ht->buckets[b], *entry;

  for ( entry = head->next; entry != nullptr;
        entry = entry->next ) {
    if ( (*ht->cmp_fn)( key, entry->data ) == 0 )
      return (struct ht_insert_rv)
               { entry, .inserted = false };
  }

  entry = malloc( sizeof(struct ht_entry) + data_size );
  *entry =
    (struct ht_entry){ .next = head->next, .prev = head };
  if ( head->next != nullptr )
    head->next->prev = entry;
  *head = (struct ht_entry){ .next = entry, .hash = hash };

  auto const lf = ++ht->size / (double)n_buckets;
  if ( lf >= ht->max_lf )
    ht_grow( ht );

  return (struct ht_insert_rv){ entry, .inserted = true };
}
