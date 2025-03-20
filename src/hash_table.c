#include "config.h"                     /* must go first */

#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "handy/ARRAY_SIZE.h"

#include "hash_table.d/fnv1a.h"
#include "hash_table.d/types.h"
#include "hash_table.d/DINT-DPTR.h"
#include "hash_table.d/HT_PRIME.h"
#include "hash_table.d/ht_cleanup.h"
#include "hash_table.d/ht_delete.h"
#include "hash_table.d/ht_empty.h"
#include "hash_table.d/ht_find.h"
#include "hash_table.d/ht_grow.h"
#include "hash_table.d/ht_init.h"
#include "hash_table.d/ht_insert_rv.h"
#include "hash_table.d/ht_insert.h"
#include "hash_table.d/ht_iter.h"
#include "hash_table.d/ht_next.h"

extern inline bool ht_empty( struct hash_table const* );

struct test_data {
  char  key[2];
  int   val;
};

#define TEST_DINT(ENTRY)      (struct test_data*)HT_DINT( (ENTRY) )
#define TEST_INSERT(HT,KEY)   ht_insert( (HT), (KEY), sizeof(struct test_data) )
#define TEST_LIT(KEY,VAL)     (struct test_data){ .key = (KEY), .val = (VAL) }

#define TEST_ASSIGN(ENTRY,KEY,VAL) \
  *TEST_DINT( (ENTRY) ) = TEST_LIT( (KEY), (VAL) )

#define TEST_INSERT_ASSIGN(HT,KEY,VAL) \
  TEST_ASSIGN( TEST_INSERT( (HT), (KEY) ).entry, (KEY), (VAL) )

constexpr double TEST_LOAD_FACTOR_MAX = 1.0;

////////// local functions ////////////////////////////////////////////////////

static ht_hash_val test_fnv1a( void const *data ) {
  struct test_data const *const test_data = data;
  return fnv1a64_mem( FNV1A64_INIT, test_data->key, 1 );
}

static void test_ht_fill( struct hash_table *ht ) {
  TEST_INSERT_ASSIGN( ht, "A", 1 );
  TEST_INSERT_ASSIGN( ht, "B", 2 );
  TEST_INSERT_ASSIGN( ht, "C", 3 );
  TEST_INSERT_ASSIGN( ht, "D", 4 );
  TEST_INSERT_ASSIGN( ht, "E", 5 );
}

static void test_ht_init( struct hash_table *ht ) {
  ht_init( ht, TEST_LOAD_FACTOR_MAX, 0, (ht_cmp_fn)&strcmp, &test_fnv1a );
}

static void test_ht_seen( struct hash_table *ht, bool seen[] ) {
  memset( seen, 0, 128 * sizeof(bool) );

  struct ht_iter it;
  ht_iter_init( &it, ht );

  for ( struct ht_entry const *entry; (entry = ht_next( &it )) != nullptr; )
    seen[ (unsigned)((struct test_data*)HT_DINT( entry ))->key[0] ] = true;
}

////////// test functions /////////////////////////////////////////////////////

#include "unit_test.h"

static bool test_find_delete() {
  TEST_FUNC_BEGIN();

  struct hash_table ht;
  test_ht_init( &ht );
  test_ht_fill( &ht );

  struct ht_entry *entry;
  entry = ht_find( &ht, "X" );
  TEST( entry == nullptr );

  entry = ht_find( &ht, "D" );
  if ( !TEST( entry != nullptr ) )
    goto end_test;

  ht_delete( &ht, entry );

  bool seen[ 128 ];
  test_ht_seen( &ht, seen );

  TEST(  seen[ 'A' ] );
  TEST(  seen[ 'B' ] );
  TEST(  seen[ 'C' ] );
  TEST( !seen[ 'D' ] );
  TEST(  seen[ 'E' ] );

end_test:
  ht_cleanup( &ht, /*free_fn=*/nullptr );
  TEST_FUNC_END();
}

static bool test_insert_delete() {
  TEST_FUNC_BEGIN();

  struct hash_table ht;
  test_ht_init( &ht );

  struct ht_insert_rv hti_rv = ht_insert( &ht, "A", sizeof(struct test_data) );
  if ( TEST( !ht_empty( &ht ) ) && TEST( hti_rv.inserted ) )
    goto end_test;
  TEST_ASSIGN( hti_rv.entry, "A", 1 );

  struct test_data const *data = TEST_DINT( hti_rv.entry );
  TEST( strcmp( data->key, "A" ) == 0 );
  TEST( data->val == 1 );

  hti_rv = ht_insert( &ht, "A", sizeof(struct test_data) );
  TEST( !hti_rv.inserted );

  ht_delete( &ht, hti_rv.entry );
  TEST( ht_empty( &ht ) );

end_test:
  ht_cleanup( &ht, /*free_fn=*/nullptr );
  TEST_FUNC_END();
}

static bool test_iter() {
  TEST_FUNC_BEGIN();

  struct hash_table ht;
  test_ht_init( &ht );
  test_ht_fill( &ht );

  bool seen[ 128 ];
  test_ht_seen( &ht, seen );

  TEST( seen[ 'A' ] );
  TEST( seen[ 'B' ] );
  TEST( seen[ 'C' ] );
  TEST( seen[ 'D' ] );
  TEST( seen[ 'E' ] );

  ht_cleanup( &ht, /*free_fn=*/nullptr );
  TEST_FUNC_END();
}

int main( int argc, char const *const argv[] ) {
  test_prog_init( argc, argv );

  test_insert_delete() &&
  test_iter() &&
  test_find_delete();
}

///////////////////////////////////////////////////////////////////////////////

struct key_val {
  char const *key, *val;
};

void insert_example() {
  struct hash_table xht, *ht = &xht;
# include "hash_table.d/insert_example.h"
}
