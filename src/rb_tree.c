#include <stddef.h>                     /* for max_align_t */
#include <stdlib.h>
#include <string.h>                     /* for memcpy(3) */

#include "rb_tree.d/DINT-DPTR.h"
#include "rb_tree.d/types.h"
#include "rb_tree.d/is_black_red.h"
#include "rb_tree.d/rb_tree_empty.h"
#include "rb_tree.d/rb_insert_rv.h"
#include "rb_tree.d/rb_node_data.h"
#include "rb_tree.d/rb_tree_cmp.h"
#include "rb_tree.d/util.h"

#include "rb_tree.d/rb_node_rotate.h"

#include "rb_tree.d/rb_delete_fixup.h"
#include "rb_tree.d/rb_insert_fixup.h"
#include "rb_tree.d/rb_transplant.h"
#include "rb_tree.d/rb_tree_minimum.h"

#include "rb_tree.d/init.h"
#include "rb_tree.d/cleanup.h"
#include "rb_tree.d/delete.h"
#include "rb_tree.d/find.h"
#include "rb_tree.d/insert.h"
#include "rb_tree.d/visit.h"

extern inline void* rb_node_data( struct rb_tree const*,
                                  struct rb_node const* );
extern inline bool rb_tree_empty( struct rb_tree const* );

#include "handy/ARRAY_SIZE.h"

#define ARRAY_END(ARRAY)          ( (ARRAY) + ARRAY_SIZE( (ARRAY) ) )

#define FOREACH_ARRAY_ELEMENT(VAR,ARRAY) \
  for ( auto VAR = (ARRAY); VAR < ARRAY_END(ARRAY); ++VAR )

enum rb_test_cmd {
  RB_TEST_INSERT,
  RB_TEST_DELETE
};
typedef enum rb_test_cmd rb_test_cmd_t;

struct rb_test_instruction {
  rb_test_cmd_t   cmd;
  char const     *key;
};
typedef struct rb_test_instruction rb_test_instruction_t;

// This sequence of instructions used to cause the tree's invariants to break,
// so it's now a test.
static rb_test_instruction_t const RB_TEST_SCRIPT[] = {
  { RB_TEST_INSERT, "cx_throw()" },
  { RB_TEST_INSERT, "CX_IMPL_DEF_ARGS(CX_IMPL_THROW_,)" },
  { RB_TEST_INSERT, "CX_IMPL_NAME2(CX_IMPL_THROW_, CX_IMPL_NARG())" },
  { RB_TEST_INSERT, "CX_IMPL_NARG()" },
  { RB_TEST_INSERT, "CX_IMPL_NARG_HELPER1(CX_IMPL_HAS_COMMA( ), CX_IMPL_HAS_COMMA( CX_IMPL_COMMA () ), CX_IMPL_NARG_( , CX_IMPL_REV_SEQ_N ))" },
  { RB_TEST_INSERT, "CX_IMPL_HAS_COMMA()" },
  { RB_TEST_INSERT, "CX_IMPL_HAS_COMMA_N" },
  { RB_TEST_DELETE, "CX_IMPL_HAS_COMMA_N" },
  { RB_TEST_INSERT, "CX_IMPL_HAS_COMMA_N" },
  { RB_TEST_INSERT, "CX_IMPL_ARG_N(, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0)" },
  { RB_TEST_DELETE, "CX_IMPL_ARG_N(, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0)" },
  { RB_TEST_DELETE, "CX_IMPL_HAS_COMMA_N" },
  { RB_TEST_DELETE, "CX_IMPL_HAS_COMMA()" },
  { RB_TEST_INSERT, "CX_IMPL_COMMA" },
  { RB_TEST_INSERT, "CX_IMPL_HAS_COMMA_N" },
  { RB_TEST_DELETE, "CX_IMPL_HAS_COMMA_N" },
  { RB_TEST_INSERT, "CX_IMPL_HAS_COMMA_N" },
  { RB_TEST_INSERT, "CX_IMPL_ARG_N(CX_IMPL_COMMA (), 1, 1, 1, 1, 1, 1, 1, 1, 0, 0)" },
  { RB_TEST_DELETE, "CX_IMPL_ARG_N(CX_IMPL_COMMA (), 1, 1, 1, 1, 1, 1, 1, 1, 0, 0)" },
  { RB_TEST_DELETE, "CX_IMPL_HAS_COMMA_N" },
  { RB_TEST_DELETE, "CX_IMPL_COMMA" },
  { RB_TEST_INSERT, "CX_IMPL_REV_SEQ_N" },
  { RB_TEST_DELETE, "CX_IMPL_REV_SEQ_N" },
  { RB_TEST_INSERT, "CX_IMPL_REV_SEQ_N" },
  { RB_TEST_INSERT, "CX_IMPL_ARG_N(, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)" },
  { RB_TEST_DELETE, "CX_IMPL_ARG_N(, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)" },
  { RB_TEST_DELETE, "CX_IMPL_REV_SEQ_N" },
  { RB_TEST_INSERT, "CX_IMPL_NARG_HELPER2(0, 0, 1)" },
  { RB_TEST_INSERT, "CX_IMPL_NARG_HELPER3_00(1)" },
  { RB_TEST_DELETE, "CX_IMPL_NARG_HELPER3_00(1)" },
  { RB_TEST_DELETE,  "CX_IMPL_NARG_HELPER2(0, 0, 1)" },
  { RB_TEST_DELETE, "CX_IMPL_NARG_HELPER1(CX_IMPL_HAS_COMMA( ), CX_IMPL_HAS_COMMA( CX_IMPL_COMMA () ), CX_IMPL_NARG_( , CX_IMPL_REV_SEQ_N ))" },
};

////////// local functions ////////////////////////////////////////////////////

#include "unit_test.h"

static bool test_check_rb_node( struct rb_tree const *tree,
                                struct rb_node const *node ) {
  TEST_FUNC_BEGIN();

  if ( node->color == RB_RED ) {
    TEST( node->child[0]->color == RB_BLACK );
    TEST( node->child[1]->color == RB_BLACK );
  }

  if ( node->child[0] != &tree->nil ) {
    TEST(
      (*tree->cmp_fn)(
        rb_node_data( tree, node->child[0] ), rb_node_data( tree, node )
      ) <= 0
    );
    TEST( test_check_rb_node( tree, node->child[0] ) );
  }

  if ( node->child[1] != &tree->nil ) {
    TEST(
      (*tree->cmp_fn)(
        rb_node_data( tree, node ), rb_node_data( tree, node->child[1] )
      ) <= 0
    );
    TEST( test_check_rb_node( tree, node->child[1] ) );
  }

  TEST_FUNC_END();
}

static bool test_check_rb_tree( struct rb_tree const *tree ) {
  TEST_FUNC_BEGIN();
  TEST( tree->root != nullptr );
  TEST( tree->root->color == RB_BLACK );
  TEST( tree->nil.color == RB_BLACK );
  TEST( test_check_rb_node( tree, tree->root ) );
  TEST_FUNC_END();
}

static bool test_rb_visitor( void *node_data, void *v_data ) {
  char const *const str = node_data;
  unsigned *const letter_offset_ptr = v_data;
  if ( TEST( str != nullptr ) )
    TEST( str[0] == (char)('A' + *letter_offset_ptr) );
  ++*letter_offset_ptr;
  return false;
}

////////// test functions /////////////////////////////////////////////////////

static bool test_insert1_find_delete( enum rb_dloc dloc ) {
  TEST_FUNC_BEGIN();
  struct rb_tree tree;
  rb_tree_init( &tree, dloc, (rb_cmp_fn)&strcmp );

  if ( !TEST( rb_tree_insert( &tree, (void*)"A", 2 ).inserted ) )
    goto end_test;
  if ( !TEST( test_check_rb_tree( &tree ) ) )
    goto end_test;

  struct rb_node *node = rb_tree_find( &tree, (void*)"A" );
  if ( TEST( node != nullptr ) ) {
    rb_tree_delete( &tree, node );
    if ( !TEST( test_check_rb_tree( &tree ) ) )
      goto end_test;
    node = rb_tree_find( &tree, (void*)"A" );
    TEST( node == nullptr );
  }

end_test:
  rb_tree_cleanup( &tree, /*free_fn=*/nullptr );
  TEST( rb_tree_empty( &tree ) );
  TEST_FUNC_END();
}

static bool test_insert2_find_delete( enum rb_dloc dloc ) {
  TEST_FUNC_BEGIN();
  struct rb_tree tree;
  rb_tree_init( &tree, dloc, (rb_cmp_fn)&strcmp );

  if ( !TEST( rb_tree_insert( &tree, (void*)"A", 2 ).inserted ) )
    goto end_test;
  if ( !TEST( test_check_rb_tree( &tree ) ) )
    goto end_test;
  if ( !TEST( rb_tree_insert( &tree, (void*)"B", 2 ).inserted ) )
    goto end_test;
  if ( !TEST( test_check_rb_tree( &tree ) ) )
    goto end_test;

  struct rb_node *node = rb_tree_find( &tree, (void*)"B" );
  if ( TEST( node != nullptr ) ) {
    rb_tree_delete( &tree, node );
    if ( !TEST( test_check_rb_tree( &tree ) ) )
      goto end_test;
    node = rb_tree_find( &tree, (void*)"B" );
    TEST( node == nullptr );
  }

end_test:
  rb_tree_cleanup( &tree, /*free_fn=*/nullptr );
  TEST( rb_tree_empty( &tree ) );
  TEST_FUNC_END();
}

static bool test_script( enum rb_dloc dloc ) {
  TEST_FUNC_BEGIN();
  struct rb_tree tree;
  rb_tree_init( &tree, dloc, (rb_cmp_fn)&strcmp );

  FOREACH_ARRAY_ELEMENT( i, RB_TEST_SCRIPT ) {
    switch ( i->cmd ) {
      case RB_TEST_INSERT:;
        size_t const size = dloc == RB_DINT ? strlen( i->key ) + 1 : 0;
        TEST( rb_tree_insert( &tree, (void*)i->key, size ).inserted );
        if ( !TEST( test_check_rb_tree( &tree ) ) )
          goto end_test;
        break;
      case RB_TEST_DELETE:
        struct rb_node *found = rb_tree_find( &tree, (void*)i->key );
        if ( TEST( found != NULL ) ) {
          rb_tree_delete( &tree, found );
          if ( !TEST( test_check_rb_tree( &tree ) ) )
            goto end_test;
          found = rb_tree_find( &tree, (void*)i->key );
          TEST( found == NULL );
        }
        break;
    } // switch
  } // for

end_test:
  rb_tree_cleanup( &tree, /*free_fn=*/NULL );
  TEST( rb_tree_empty( &tree ) );
  TEST_FUNC_END();
}

static bool test_various( enum rb_dloc dloc ) {
  TEST_FUNC_BEGIN();
  struct rb_tree tree;
  rb_tree_init( &tree, dloc, (rb_cmp_fn)&strcmp );

  // test insertion
  TEST( rb_tree_insert( &tree, (void*)"A", 2 ).inserted );
  if ( !TEST( test_check_rb_tree( &tree ) ) )
    goto end_test;
  TEST( rb_tree_insert( &tree, (void*)"B", 2 ).inserted );
  if ( !TEST( test_check_rb_tree( &tree ) ) )
    goto end_test;
  TEST( rb_tree_insert( &tree, (void*)"C", 2 ).inserted );
  if ( !TEST( test_check_rb_tree( &tree ) ) )
    goto end_test;
  TEST( rb_tree_insert( &tree, (void*)"D", 2 ).inserted );
  if ( !TEST( test_check_rb_tree( &tree ) ) )
    goto end_test;

  // test insertion with existing data
  struct rb_insert_rv rbi_rv = rb_tree_insert( &tree, (void*)"A", 2 );
  if ( !TEST( test_check_rb_tree( &tree ) ) )
    goto end_test;
  if ( TEST( !rbi_rv.inserted ) )
    TEST( strcmp( rb_node_data( &tree, rbi_rv.node ), "A" ) == 0 );

  // test visitor
  unsigned letter_offset = 0;
  TEST( rb_tree_visit( &tree, &test_rb_visitor, &letter_offset ) == nullptr );

  // test find
  struct rb_node *node = rb_tree_find( &tree, "A" );
  if ( TEST( node != nullptr ) ) {
    TEST( strcmp( rb_node_data( &tree, node ), "A" ) == 0 );

    // test delete
    rb_tree_delete( &tree, node );
    if ( !TEST( test_check_rb_tree( &tree ) ) )
      goto end_test;

    // test visitor again
    letter_offset = 1; // skip "A"
    TEST( rb_tree_visit( &tree, &test_rb_visitor, &letter_offset ) == nullptr );
  }

end_test:
  rb_tree_cleanup( &tree, /*free_fn=*/nullptr );
  TEST( rb_tree_empty( &tree ) );
  TEST_FUNC_END();
}

int main( int argc, char const *const argv[] ) {
  test_prog_init( argc, argv );

  test_insert1_find_delete( RB_DINT );
  test_insert1_find_delete( RB_DPTR );
  test_insert2_find_delete( RB_DINT );
  test_insert2_find_delete( RB_DPTR );

  test_various( RB_DINT );
  test_various( RB_DPTR );

  test_script( RB_DINT );
  test_script( RB_DPTR );
}
