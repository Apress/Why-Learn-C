#define UNDERLYING_TYPE(ENUM_TYPE)                   \
  typeof( STATIC_IF( IS_SIGNED_TYPE(ENUM_TYPE),      \
                     TO_SIGNED_EXPR( (ENUM_TYPE)0 ), \
                     TO_UNSIGNED_EXPR( (ENUM_TYPE)0 ) ) )
