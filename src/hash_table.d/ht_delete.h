void ht_delete( struct hash_table *ht,
                struct ht_entry *entry ) {
  entry->prev->next = entry->next;
  if ( entry->next != nullptr )
    entry->next->prev = entry->prev;
  free( entry );
  --ht->size;
}
