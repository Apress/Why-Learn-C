while ( !atomic_load_explicit( &work_avail,
                               memory_order_consume ) )
  ; // wait
char *const path = *(char**)islist_peek( work_avail );
