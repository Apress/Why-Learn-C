#define IS_POINTER_EXPR(P)     \
  _Generic( &(typeof((P))){ }, \
    typeof(*(P)) ** : true,    \
    default         : false    \
  )
