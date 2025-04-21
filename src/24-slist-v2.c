#include "config.h"                     /* must go first */

#include <stddef.h>                     /* for max_align_t */
#include <stdlib.h>
#include <string.h>

#include "slist-v2.d/DINT-DPTR.h"
#include "slist-v2.d/structs.h"
#include "slist-v2.d/free_if.h"
#include "slist-v2.d/dup_str.h"
#include "slist-v2.d/not_contains_str.h"
#include "slist-v2.d/front-back-empty.h"

void slist_front_int_example( struct slist *list ) {
[[maybe_unused]]
# include "slist-v2.d/slist_front_int_example.h"
}

void slist_front_ptr_example( struct slist *list ) {
[[maybe_unused]]
# include "slist-v2.d/slist_front_ptr_example.h"
}

#include "slist-v2.d/init-cleanup.h"
#include "slist-v2.d/pop.h"
#include "slist-v2.d/push.h"

extern inline struct slink* slist_back( struct slist* );
extern inline bool slist_empty( struct slist* );
extern inline struct slink* slist_front( struct slist* );
extern inline void slist_init( struct slist* );

////////// test functions /////////////////////////////////////////////////////

#include "unit_test.h"

static bool test_push_pop_front_back() {
  TEST_FUNC_BEGIN();
  struct slist list;
  slist_init( &list );
  TEST( slist_empty( &list ) );

  *(int*)SLIST_DINT( slist_push_back( &list, sizeof(int) )->data ) = 1;
  TEST( !slist_empty( &list ) );

  TEST( *(int*)SLIST_DINT( slist_front( &list )->data ) == 1 );
  TEST( *(int*)SLIST_DINT( slist_back ( &list )->data ) == 1 );

  *(int*)SLIST_DINT( slist_push_back( &list, sizeof(int) )->data ) = 2;
  TEST( *(int*)SLIST_DINT( slist_front( &list )->data ) == 1 );
  TEST( *(int*)SLIST_DINT( slist_back ( &list )->data ) == 2 );

  *(int*)SLIST_DINT( slist_push_back( &list, sizeof(int) )->data ) = 3;
  TEST( *(int*)SLIST_DINT( slist_front( &list )->data ) == 1 );
  TEST( *(int*)SLIST_DINT( slist_back ( &list )->data ) == 3 );

  slist_pop_back( &list );
  TEST( *(int*)SLIST_DINT( slist_front( &list )->data ) == 1 );
  TEST( *(int*)SLIST_DINT( slist_back ( &list )->data ) == 2 );

  slist_pop_front( &list );
  TEST( *(int*)SLIST_DINT( slist_front( &list )->data ) == 2 );
  TEST( *(int*)SLIST_DINT( slist_back ( &list )->data ) == 2 );

  slist_cleanup( &list, /*free_fn=*/nullptr );
  TEST( slist_empty( &list ) );
  TEST_FUNC_END();
}

int main( int argc, char const *const argv[] ) {
  test_prog_init( argc, argv );
  test_push_pop_front_back();
}
