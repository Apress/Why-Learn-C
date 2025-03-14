#define TO_UNSIGNED_EXPR(N) (                   \
  STATIC_ASSERT_EXPR( IS_INTEGRAL_EXPR( (N) ),  \
    #N " must be integral" ) *                  \
  STATIC_IF( sizeof(N) == sizeof(char ),        \
    (unsigned char     )(N),                    \
  STATIC_IF( sizeof(N) == sizeof(short),        \
    (unsigned short    )(N),                    \
  STATIC_IF( sizeof(N) == sizeof(int  ),        \
    (unsigned int      )(N),                    \
  STATIC_IF( sizeof(N) == sizeof(long ),        \
    (unsigned long     )(N),                    \
    (unsigned long long)(N) ) ) ) ) )
