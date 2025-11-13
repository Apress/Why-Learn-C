#include "config.h"                     /* must go first */

#include "type_traits.d/INT_MAX_EXPR.h"
#include "type_traits.d/INT_MIN_EXPR.h"
#include "type_traits.d/IS_ARITHMETIC_EXPR.h"
#include "type_traits.d/IS_ARRAY_EXPR.h"
#include "type_traits.d/IS_C_STR_EXPR.h"
#include "type_traits.d/IS_FLOATING_POINT_EXPR.h"
#include "type_traits.d/IS_INTEGRAL_EXPR.h"
#include "type_traits.d/IS_POINTER_EXPR.h"
#include "type_traits.d/IS_SAME_TYPE.h"
#include "type_traits.d/IS_SIGNED_EXPR.h"
#include "type_traits.d/IS_SIGNED_TYPE.h"
#include "type_traits.d/IS_TYPE_EXPR.h"
#include "type_traits.d/IS_UNSIGNED_EXPR.h"
#include "type_traits.d/TO_SIGNED_EXPR.h"
#include "type_traits.d/TO_UNSIGNED_EXPR.h"
#include "type_traits.d/UNDERLYING_TYPE.h"
#include "util/STATIC_ASSERT_EXPR.h"
#include "util/STATIC_IF.h"

////////// test functions /////////////////////////////////////////////////////

#include "unit_test.h"

#include <limits.h>

char      ac[1];
int       ai[1];
float     f;
int       i;
char     *pc;
int      *pi;
unsigned  u;

static bool test_IS_ARITHMETIC_EXPR() {
  TEST_FUNC_BEGIN();
  TEST( !IS_ARITHMETIC_EXPR( ai ) );
  TEST(  IS_ARITHMETIC_EXPR( f ) );
  TEST(  IS_ARITHMETIC_EXPR( i ) );
  TEST( !IS_ARITHMETIC_EXPR( pi ) );
  TEST(  IS_ARITHMETIC_EXPR( u ) );
  TEST_FUNC_END();
}

static bool test_IS_INTEGRAL_EXPR() {
  TEST_FUNC_BEGIN();
  TEST( !IS_INTEGRAL_EXPR( ai ) );
  TEST( !IS_INTEGRAL_EXPR( f ) );
  TEST(  IS_INTEGRAL_EXPR( i ) );
  TEST( !IS_INTEGRAL_EXPR( pi ) );
  TEST(  IS_INTEGRAL_EXPR( u ) );
  TEST_FUNC_END();
}

static bool test_IS_SIGNED_EXPR() {
  TEST_FUNC_BEGIN();
  TEST( !IS_SIGNED_EXPR( ai ) );
  TEST( !IS_SIGNED_EXPR( f ) );
  TEST(  IS_SIGNED_EXPR( i ) );
  TEST( !IS_SIGNED_EXPR( pi ) );
  TEST( !IS_SIGNED_EXPR( u ) );
  TEST_FUNC_END();
}

static bool test_IS_SIGNED_TYPE() {
  TEST_FUNC_BEGIN();
  TEST( IS_SIGNED_TYPE( short ) );
  TEST( IS_SIGNED_TYPE( int ) );
  TEST( IS_SIGNED_TYPE( long ) );
  TEST( IS_SIGNED_TYPE( long long ) );
  TEST_FUNC_END();
}

static bool test_IS_TYPE_EXPR() {
  TEST_FUNC_BEGIN();
  TEST( IS_TYPE_EXPR( double, 0.0 ) );
  TEST( IS_TYPE_EXPR( int, 0 ) );
  TEST( IS_TYPE_EXPR( long, 0L ) );
  TEST( IS_TYPE_EXPR( long long, 0LL ) );
  TEST( IS_TYPE_EXPR( unsigned, 0U ) );
  TEST( IS_TYPE_EXPR( unsigned long, 0UL ) );
  TEST( IS_TYPE_EXPR( unsigned long long, 0ULL ) );
  TEST_FUNC_END();
}

static bool test_IS_UNSIGNED_EXPR() {
  TEST_FUNC_BEGIN();
  TEST( !IS_UNSIGNED_EXPR( ai ) );
  TEST( !IS_UNSIGNED_EXPR( f ) );
  TEST( !IS_UNSIGNED_EXPR( i ) );
  TEST( !IS_UNSIGNED_EXPR( pi ) );
  TEST(  IS_UNSIGNED_EXPR( u ) );
  TEST_FUNC_END();
}

static bool test_IS_UNSIGNED_TYPE() {
  TEST_FUNC_BEGIN();
  TEST( IS_UNSIGNED_TYPE( unsigned short ) );
  TEST( IS_UNSIGNED_TYPE( unsigned int ) );
  TEST( IS_UNSIGNED_TYPE( unsigned long ) );
  TEST( IS_UNSIGNED_TYPE( unsigned long long ) );
  TEST_FUNC_END();
}

static bool test_TO_SIGNED_EXPR() {
  TEST_FUNC_BEGIN();
  TEST( IS_TYPE_EXPR( int, TO_SIGNED_EXPR( 0u ) ) );
  TEST( IS_TYPE_EXPR( long, TO_SIGNED_EXPR( 0ul ) ) );
//TEST( IS_TYPE_EXPR( long long, TO_SIGNED_EXPR( 0ull ) ) );
  TEST_FUNC_END();
}

static bool test_TO_UNSIGNED_EXPR() {
  TEST_FUNC_BEGIN();
  TEST( IS_TYPE_EXPR( unsigned, TO_UNSIGNED_EXPR( 0 ) ) );
  TEST( IS_TYPE_EXPR( unsigned long, TO_UNSIGNED_EXPR( 0ul ) ) );
//TEST( IS_TYPE_EXPR( unsigned long long, TO_UNSIGNED_EXPR( 0ull ) ) );
  TEST_FUNC_END();
}

enum test_enum_underlying_type : unsigned char {
  TEST_ENUM_UNDERLYING_TYPE
};

static bool test_UNDERLYING_TYPE() {
  enum test_enum_underlying_type e;
  TEST_FUNC_BEGIN();
  TEST( IS_SAME_TYPE( typeof(e), unsigned char ) );
  TEST_FUNC_END();
}

int main( int argc, char const *const argv[] ) {
  test_prog_init( argc, argv );

  TEST( INT_MAX_EXPR(i) == INT_MAX );
  TEST( INT_MIN_EXPR(i) == INT_MIN );
  TEST( INT_MAX_EXPR(u) == UINT_MAX );
  TEST( INT_MIN_EXPR(u) == 0 );

  TEST(  IS_ARRAY_EXPR( ai ) );
  TEST( !IS_ARRAY_EXPR( pi ) );

  TEST(  IS_C_STR_EXPR( ac ) );
  TEST( !IS_C_STR_EXPR( ai ) );
  TEST( !IS_C_STR_EXPR( pi ) );
  TEST(  IS_C_STR_EXPR( pc ) );

  TEST( !IS_FLOATING_POINT_EXPR( ai ) );
  TEST(  IS_FLOATING_POINT_EXPR( f ) );
  TEST( !IS_FLOATING_POINT_EXPR( i ) );
  TEST( !IS_FLOATING_POINT_EXPR( pi ) );
  TEST( !IS_FLOATING_POINT_EXPR( u ) );

  TEST( !IS_POINTER_EXPR( ai ) );
  TEST(  IS_POINTER_EXPR( pi ) );

  TEST(  IS_SAME_TYPE( int, int ) );
  TEST(  IS_SAME_TYPE( int, int const ) );
  TEST(  IS_SAME_TYPE( int const, int ) );
  TEST(  IS_SAME_TYPE( int const, int const ) );

  TEST(  IS_SAME_TYPE( int*, int* ) );
  TEST( !IS_SAME_TYPE( int*, int const* ) );
  TEST( !IS_SAME_TYPE( int const*, int* ) );
  TEST(  IS_SAME_TYPE( int const*, int const* ) );

  TEST(  IS_SAME_TYPE( int (*)(), int (*)() ) );
  TEST( !IS_SAME_TYPE( int (*)(), void (*)() ) );
  TEST( !IS_SAME_TYPE( int (*)(), int (*)(int) ) );

  TEST( !IS_SAME_TYPE( int**, int const** ) );

  TEST( !IS_SAME_TYPE( int, unsigned ) );
  TEST( !IS_SAME_TYPE( unsigned, int ) );

  TEST(  IS_SAME_TYPE( struct S, struct S ) );
  TEST(  IS_SAME_TYPE( void, void ) );

  (void)( test_IS_SIGNED_EXPR() &&
          test_IS_UNSIGNED_EXPR() &&
          test_IS_INTEGRAL_EXPR() &&
          test_IS_ARITHMETIC_EXPR() );

  test_IS_SIGNED_TYPE();
  test_IS_UNSIGNED_TYPE();

  test_IS_TYPE_EXPR();

  test_TO_SIGNED_EXPR();
  test_TO_UNSIGNED_EXPR();
  test_UNDERLYING_TYPE();
}
