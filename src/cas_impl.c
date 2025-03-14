typedef int T;
typedef T _Atomic A;

#include "cas_impl.d/cas_impl.h"

///////////////////////////////////////////////////////////////////////////////

enum cas_result cas_weak_impl( A*, T*, T ) {
  return CAS_EQUAL;
}

extern inline bool compare_exchange_weak( A*, T*, T );

int main() {
}
