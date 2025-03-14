work_list = islist_push( work_list, sizeof(char*) );
*(char**)islist_peek( work_list ) = path;
atomic_store_explicit( &work_avail, work_list,
                       memory_order_release );
