#include "config.h"                     /* must go first */

#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>

#include "c_exception.d/cx_catch.h"
#include "c_exception.d/cx_exception.h"
#include "c_exception.d/cx_finally.h"
#include "c_exception.d/cx_terminate.h"
#include "c_exception.d/cx_throw.h"
#include "c_exception.d/cx_try-v2.h"

#include "c_exception.d/cx_impl_state-v3.h"
#include "c_exception.d/cx_impl_try_block-v3.h"

static thread_local struct cx_impl_try_block *cx_impl_try_block_head;

#include "c_exception.d/cx_impl_catch.h"
#include "c_exception.d/cx_impl_throw-v2.h"
#include "c_exception.d/cx_impl_try_cond-v3.h"

#pragma clang diagnostic ignored "-Wdangling-else"
#pragma clang diagnostic ignored "-Wshadow"

#define EX_FILE_NOT_FOUND         1
#include "c_exception.d/read_file.h"    /* ensure it compiles */

////////// local functions ////////////////////////////////////////////////////

static inline struct cx_exception* cx_current_exception() {
  return cx_impl_exception.thrown_file == nullptr ?
    nullptr : &cx_impl_exception;
}

////////// test functions /////////////////////////////////////////////////////

#include "unit_test.h"

#define TEST_XID_ANY              0x0100
#define TEST_XID_01               0x0101
#define TEST_XID_02               0x0102

static bool test_no_throw( void ) {
  TEST_FUNC_BEGIN();
  unsigned n_try = 0, n_catch = 0, n_finally = 0;
  try {
    ++n_try;
  }
  catch ( TEST_XID_01 ) {
    ++n_catch;
  }
  finally {
    ++n_finally;
    TEST( cx_current_exception() == nullptr );
  }
  TEST( n_try == 1 );
  TEST( n_catch == 0 );
  TEST( n_finally == 1 );
  TEST( cx_current_exception() == nullptr );
  TEST_FUNC_END();
}

static bool test_throw_catch_1( void ) {
  TEST_FUNC_BEGIN();
  unsigned volatile n_try = 0;
  unsigned n_catch_1 = 0, n_catch_2 = 0, n_finally = 0;
  try {
    ++n_try;
    throw ( TEST_XID_01 );
  }
  catch ( TEST_XID_01 ) {
    ++n_catch_1;
    TEST( cx_current_exception() != nullptr );
  }
  catch ( TEST_XID_02 ) {
    ++n_catch_2;
  }
  finally {
    ++n_finally;
    TEST( cx_current_exception() != nullptr );
  }
  TEST( n_try == 1 );
  TEST( n_catch_1 == 1 );
  TEST( n_catch_2 == 0 );
  TEST( n_finally == 1 );
  TEST( cx_current_exception() == nullptr );
  TEST_FUNC_END();
}
static bool test_throw_catch_2( void ) {
  TEST_FUNC_BEGIN();
  unsigned volatile n_try = 0;
  unsigned n_catch_1 = 0, n_catch_2 = 0, n_finally = 0;
  try {
    ++n_try;
    throw ( TEST_XID_02 );
  }
  catch ( TEST_XID_01 ) {
    ++n_catch_1;
  }
  catch ( TEST_XID_02 ) {
    ++n_catch_2;
    TEST( cx_current_exception() != nullptr );
  }
  finally {
    ++n_finally;
    TEST( cx_current_exception() != nullptr );
  }
  TEST( n_try == 1 );
  TEST( n_catch_1 == 0 );
  TEST( n_catch_2 == 1 );
  TEST( n_finally == 1 );
  TEST( cx_current_exception() == nullptr );
  TEST_FUNC_END();
}

static void test_throw_from_a_called_function_function( int xid ) {
  throw ( xid );
}

static bool test_throw_from_a_called_function( void ) {
  TEST_FUNC_BEGIN();
  unsigned volatile n_try = 0;
  unsigned n_catch = 0, n_finally = 0;
  try {
    ++n_try;
    test_throw_from_a_called_function_function( TEST_XID_01 );
  }
  catch ( TEST_XID_01 ) {
    ++n_catch;
    TEST( cx_current_exception() != nullptr );
  }
  finally {
    ++n_finally;
    TEST( cx_current_exception() != nullptr );
  }
  TEST( n_try == 1 );
  TEST( n_catch == 1 );
  TEST( n_finally == 1 );
  TEST( cx_current_exception() == nullptr );
  TEST_FUNC_END();
}

static bool test_throw_from_nested_catch( void ) {
  TEST_FUNC_BEGIN();
  unsigned volatile n_inner_try = 0, n_outer_try = 0;
  unsigned volatile n_inner_catch = 0, n_inner_finally = 0;
  unsigned n_outer_catch = 0, n_outer_finally = 0;
  try {
    ++n_outer_try;
    try {
      ++n_inner_try;
      throw ( TEST_XID_01 );
    }
    catch ( TEST_XID_01 ) {
      ++n_inner_catch;
      throw ( TEST_XID_02 );
    }
    finally {
      ++n_inner_finally;
    }
  }
  catch ( TEST_XID_02 ) {
    ++n_outer_catch;
  }
  finally {
    ++n_outer_finally;
  }
  TEST( n_inner_try == 1 );
  TEST( n_inner_catch == 1 );
  TEST( n_inner_finally == 1 );
  TEST( n_outer_try == 1 );
  TEST( n_outer_catch == 1 );
  TEST( n_outer_finally == 1 );
  TEST( cx_current_exception() == nullptr );
  TEST_FUNC_END();
}

static bool test_rethrow_in_catch( void ) {
  TEST_FUNC_BEGIN();
  unsigned volatile n_inner_try = 0, n_outer_try = 0;
  unsigned volatile n_inner_catch = 0, n_inner_finally = 0;
  unsigned n_outer_catch = 0, n_outer_finally = 0;
  try {
    ++n_outer_try;
    try {
      ++n_inner_try;
      throw ( TEST_XID_01 );
    }
    catch ( TEST_XID_01 ) {
      ++n_inner_catch;
      throw ( TEST_XID_01 );
    }
    finally {
      ++n_inner_finally;
    }
  }
  catch ( TEST_XID_01 ) {
    ++n_outer_catch;
  }
  finally {
    ++n_outer_finally;
  }
  TEST( n_inner_try == 1 );
  TEST( n_inner_catch == 1 );
  TEST( n_inner_finally == 1 );
  TEST( n_outer_try == 1 );
  TEST( n_outer_catch == 1 );
  TEST( n_outer_finally == 1 );
  TEST( cx_current_exception() == nullptr );
  TEST_FUNC_END();
}

int main( int argc, char const *const argv[] ) {
  test_prog_init( argc, argv );
  test_no_throw();
  test_throw_catch_1();
  test_throw_catch_2();
  test_throw_from_a_called_function();
  test_throw_from_nested_catch();
  test_rethrow_in_catch();
}
