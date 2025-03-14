struct ht_entry* ht_next( struct ht_iter *it ) {
  for (;;) {
    assert( it->n_buckets == HT_PRIME[it->ht->prime_idx] );
    if ( it->next != nullptr ) {
      auto const entry = it->next;
      it->next = it->next->next;
      return entry;
    }
    if ( ++it->bucket_idx == it->n_buckets )
      return nullptr;
    it->next = it->ht->buckets[ it->bucket_idx ].next;
  }
}
