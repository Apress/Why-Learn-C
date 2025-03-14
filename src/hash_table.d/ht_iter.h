struct ht_iter {
  struct hash_table  *ht;
  struct ht_entry    *next;
  unsigned            bucket_idx;
  unsigned            n_buckets;
};

void ht_iter_init( struct ht_iter *it,
                   struct hash_table *ht ) {
  *it = (struct ht_iter){
    .ht = ht,
    .bucket_idx = (unsigned)-1,
    .n_buckets = HT_PRIME[ ht->prime_idx ]
  };
}
