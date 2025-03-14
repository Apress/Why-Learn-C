struct ht_entry* ht_find( struct hash_table *ht,
                          void const *key ) {
  auto const b =
    (*ht->hash_fn)( key ) % HT_PRIME[ ht->prime_idx ];
  for ( auto entry = ht->buckets[b].next; entry != nullptr;
        entry = entry->next ) {
    if ( (*ht->cmp_fn)( key, entry->data ) == 0 )
      return entry;
  }
  return nullptr;
}
