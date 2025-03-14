static void ht_grow( struct hash_table *ht ) {
  auto const new_n_buckets = HT_PRIME[ ++ht->prime_idx ];
  struct ht_entry *const new_buckets =
    calloc( new_n_buckets, sizeof(struct ht_entry) );

  for ( unsigned b = 0; b < new_n_buckets; ++b ) {
    auto const hash = ht->buckets[b].hash;
    for ( struct ht_entry *entry = ht->buckets[b].next,
          *next;
          entry != nullptr; entry = next ) {
      auto const new_head =
        &new_buckets[ hash % new_n_buckets ];

      next = entry->next;
      entry->next = new_head->next;
      entry->prev = new_head;

      if ( new_head->next != nullptr )
        new_head->next->prev = entry;
      new_head->next = entry;
      new_head->hash = hash;
    }
  }

  free( ht->buckets );
  ht->buckets = new_buckets;
}
