struct islist*
islist_lfpop( struct islist *_Atomic *plist ) {
  struct islist *head =
    atomic_load_explicit( plist, memory_order_relaxed );

  while ( head != nullptr &&
          !atomic_compare_exchange_weak_explicit( plist,
            &head, head->next, memory_order_release,
            memory_order_relaxed ) );

  return head;
}
