ht_hash_val ht_fnv1a( void const *data ) {
  struct test_entry const *const entry = data;
  return fnv1a( entry->key, 1 );
}
