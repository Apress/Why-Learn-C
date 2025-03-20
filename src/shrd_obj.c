#include "config.h"                     /* must go first */

#include <stdatomic.h>
#include <stddef.h>
#include <stdlib.h>

#include "shrd_obj.d/shrd_obj.h"
#include "shrd_obj.d/shrd_dec.h"
#include "shrd_obj.d/shrd_inc.h"
#include "shrd_obj.d/shrd_new.h"

#define SHRD_DINT(SO)       ( (void*)(SO)->data )
#define SHRD_DPTR(SO)       ( *(void**)SHRD_DINT( (SO) ) )

extern inline struct shrd_obj* shrd_inc( struct shrd_obj* );

////////// test functions /////////////////////////////////////////////////////

#include "unit_test.h"

static unsigned free_count;

static void test_free( struct shrd_obj *so ) {
  ++free_count;
  free( so );
}

int main( int argc, char const *const argv[] ) {
  test_prog_init( argc, argv );

  struct shrd_obj *const so1 = shrd_new( sizeof(int), &test_free );
  TEST( so1->ref_cnt == 1 );
  *(int*)SHRD_DINT( so1 ) = 42;

  struct shrd_obj *const so2 = shrd_inc( so1 );
  TEST( so2->ref_cnt == 2 );

  TEST( !shrd_dec( so1 ) );
  TEST( so2->ref_cnt == 1 );
  TEST( *(int*)SHRD_DINT( so1 ) == 42 );

  TEST( shrd_dec( so1 ) );
  TEST( free_count == 1 );
}
