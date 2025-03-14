typedef int         (*ht_cmp_fn)(void const*, void const*);
typedef void        (*ht_free_fn)(void*);
typedef uint64_t      ht_hash_val;
typedef ht_hash_val (*ht_hash_fn)(void const*);

struct ht_entry {
  struct ht_entry    *next;
  union {
    ht_hash_val       hash;       // for fake head entries
    struct ht_entry  *prev;       // for real entries
  };
  alignas(max_align_t) char data[];
};

struct hash_table {
  struct ht_entry    *buckets;
  ht_cmp_fn           cmp_fn;
  ht_hash_fn          hash_fn;
  double              max_lf;     // maximum load factor
  unsigned            size;       // number of entries
  unsigned            prime_idx;  // index into HT_PRIME
};
