void ht_cleanup( struct hash_table *ht,
                 ht_free_fn free_fn ) {
  if ( ht == nullptr )
    return;
  for ( unsigned b = 0; b < HT_PRIME[ ht->prime_idx ];
        ++b ) {
    for ( struct ht_entry *entry = ht->buckets[b].next,
          *next;
          entry != nullptr; entry = next ) {
      if ( free_fn != nullptr )
        (*free_fn)( entry->data );
      next = entry->next;
      free( entry );
    }
  }
  free( ht->buckets );
  *ht = (struct hash_table){ };
}
