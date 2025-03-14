#include "stdc_threads.h"
#include <stdlib.h>

struct slist {
  struct slist *next;
  void         *data;
};

#include "slist-v1-mtx.d/slist-v1-mtx.h"

////////// test functions /////////////////////////////////////////////////////

#include "unit_test.h"

int main( int argc, char const *const argv[] ) {
  test_prog_init( argc, argv );

  struct slist *list = nullptr;
  mtx_t list_mtx;
  mtx_init( &list_mtx, mtx_plain );

  slist_push_mtx( &list, (void*)1, &list_mtx );
  TEST( (intptr_t)slist_peek_mtx( list, &list_mtx ) == 1 );

  slist_push_mtx( &list, (void*)2, &list_mtx );
  TEST( (intptr_t)slist_peek_mtx( list, &list_mtx ) == 2 );

  TEST( (intptr_t)slist_pop_mtx( &list, &list_mtx ) == 2 );
  TEST( (intptr_t)slist_pop_mtx( &list, &list_mtx ) == 1 );

  mtx_destroy( &list_mtx );
}
