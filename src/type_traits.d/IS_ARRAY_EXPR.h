#define IS_ARRAY_EXPR(A)      \
  _Generic( &(A),             \
    typeof(*(A)) (*)[]: true, \
    default           : false \
  )
