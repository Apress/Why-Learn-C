void ht_init( struct hash_table *ht, double max_lf,
              unsigned est_size, ht_cmp_fn cmp_fn,
              ht_hash_fn hash_fn ) {
  unsigned prime_idx = 0;
  for ( ; prime_idx < ARRAY_SIZE(HT_PRIME); ++prime_idx ) {
    if ( HT_PRIME[ prime_idx ] * max_lf >= est_size )
      break;
  }
  *ht = (struct hash_table){
    .buckets = calloc( HT_PRIME[ prime_idx ],
                       sizeof(struct ht_entry) ),
    .cmp_fn = cmp_fn,
    .hash_fn = hash_fn,
    .max_lf = max_lf,
    .prime_idx = prime_idx
  };
}
