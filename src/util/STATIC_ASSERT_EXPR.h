#define STATIC_ASSERT_EXPR(EXPR,MSG) \
  (!!sizeof(struct { static_assert((EXPR), MSG); int i; }))
