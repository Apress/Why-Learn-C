#include <stdlib.h>

#include "slist-v1.d/struct.h"
#include "slist-v1.d/functions.h"
#include "user.d/slist_find.h"
#include "slist-v1.d/const_slist_find.h"
#include "slist-v1.d/slist_find.h"

#define nonconst_slist_find       slist_find

////////// test functions /////////////////////////////////////////////////////

static bool equal_fn( void const *list_data, void const *pred_data ) {
  return (intptr_t)list_data == (intptr_t)pred_data;
}

#include "unit_test.h"

int main( int argc, char const *const argv[] ) {
  test_prog_init( argc, argv );

  struct slist *list = slist_push( nullptr, (void*)1 );
  TEST( (intptr_t)slist_peek( list ) == 1 );

  list = slist_push( list, (void*)2 );
  TEST( (intptr_t)slist_peek( list ) == 2 );

  struct slist *const found = slist_find( list, &equal_fn, (void*)2 );
  if ( TEST( found != nullptr ) )
    TEST( (intptr_t)found->data == 2 );

  TEST( (intptr_t)slist_pop( &list ) == 2 );
  TEST( (intptr_t)slist_pop( &list ) == 1 );
}
