#define VERS_PTR(T)   struct { T *ptr; uintptr_t vers; }

typedef VERS_PTR(struct islist) islist_vptr;

struct islist* islist_lfpop( islist_vptr _Atomic *plist ) {
  islist_vptr head =
    atomic_load_explicit( plist, memory_order_relaxed );

  while ( head.ptr != nullptr ) {
    islist_vptr const new_next =
      { head.ptr->next, head.vers + 1 };
    if ( atomic_compare_exchange_weak_explicit( plist,
           &head, new_next, memory_order_release,
           memory_order_relaxed ) )
      break;
  }

  return head.ptr;
}
