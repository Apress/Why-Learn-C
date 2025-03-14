#define TO_SIGNED_EXPR(N) (                     \
  STATIC_ASSERT_EXPR( IS_INTEGRAL_EXPR( (N) ),  \
    #N " must be integral" ) *                  \
  STATIC_IF( sizeof(N) == sizeof(char ),        \
    (signed char)(N),                           \
  STATIC_IF( sizeof(N) == sizeof(short),        \
    (short      )(N),                           \
  STATIC_IF( sizeof(N) == sizeof(int  ),        \
    (int        )(N),                           \
  STATIC_IF( sizeof(N) == sizeof(long ),        \
    (long       )(N),                           \
    (long long  )(N) ) ) ) ) )
