bool shrd_dec( struct shrd_obj *so ) {
  if ( atomic_fetch_sub_explicit( &so->ref_cnt, 1,
         memory_order_acq_rel ) == 1 ) {
    if ( so->free_fn != nullptr )
      (*so->free_fn)( so );
    return true;
  }
  return false;
}
