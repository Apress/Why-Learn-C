struct shrd_obj* shrd_new( size_t data_size,
                           shrd_free_fn free_fn ) {
  struct shrd_obj *const so =
    malloc( sizeof(struct shrd_obj) + data_size );
  atomic_init( &so->ref_cnt, 1 );
  so->free_fn = free_fn;
  return so;
}
