inline struct shrd_obj* shrd_inc( struct shrd_obj *so ) {
  atomic_fetch_add_explicit( &so->ref_cnt, 1,
                             memory_order_relaxed );
  return so;
}
