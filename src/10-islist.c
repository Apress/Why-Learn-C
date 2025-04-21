#include "config.h"                     /* must go first */

#include <stddef.h>
#include <stdlib.h>

#include "islist.d/struct.h"
#include "islist.d/functions.h"

////////// test functions /////////////////////////////////////////////////////

#include "unit_test.h"

int main( int argc, char const *const argv[] ) {
  test_prog_init( argc, argv );

  struct islist *list = islist_push( nullptr, sizeof(int) );
  *(int*)islist_peek( list ) = 1;
  TEST( *(int*)islist_peek( list ) == 1 );

  list = islist_push( list, sizeof(int) );
  *(int*)islist_peek( list ) = 2;
  TEST( *(int*)islist_peek( list ) == 2 );

  islist_pop( &list );
  TEST( *(int*)islist_peek( list ) == 1 );
  islist_pop( &list );
  TEST( islist_peek( list ) == nullptr );
}
