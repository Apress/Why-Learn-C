#include "stdc_threads.h"

static bool load_bool_mtx( bool *src, mtx_t *mtx ) {
  mtx_lock( mtx );
  bool const value = *src;
  mtx_unlock( mtx );
  return value;
}

bool  shutdown;
mtx_t shutdown_mtx;

#include "cnd_example.d/consumer_main.h"
#include "cnd_example.d/producer_main.h"

///////////////////////////////////////////////////////////////////////////////

void suppress_unused_function_warnings() {
  consumer_main( nullptr );
  producer_main( nullptr );
}

int main() {
}
