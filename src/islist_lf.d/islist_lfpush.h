void islist_lfpush( struct islist *_Atomic *plist,
                    size_t size ) {
  struct islist *const new_head =
    malloc( sizeof(struct islist) + size );
  new_head->next =
    atomic_load_explicit( plist, memory_order_relaxed );

  while ( !atomic_compare_exchange_weak_explicit( plist,
            &new_head->next, new_head,
            memory_order_release, memory_order_relaxed ) );
}
