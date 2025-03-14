while ( !atomic_load_explicit( &work_avail,
                               memory_order_acquire ) )
  ; // wait
char *const path = *(char**)islist_peek( work_list );
