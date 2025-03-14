enum cas_result {
  CAS_EQUAL, CAS_NOT_EQUAL, CAS_SPURIOUS_FAILURE
};

enum cas_result cas_weak_impl( A *pv, T *expected,
                               T want );

inline bool atomic_compare_exchange_weak( A *pv,
                                          T *expected,
                                          T want ) {
  return cas_weak_impl( pv, expected, want ) == CAS_EQUAL;
}

bool atomic_compare_exchange_strong( A *pv, T *expected,
                                     T want ) {
  enum cas_result cr;
  do {
    cr = cas_weak_impl( pv, expected, want );
  } while ( cr == CAS_SPURIOUS_FAILURE );
  return cr == CAS_EQUAL;
}
