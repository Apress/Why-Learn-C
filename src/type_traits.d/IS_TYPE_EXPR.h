#define IS_TYPE_EXPR(T,E) \
  _Generic( (E),          \
    T       : true,       \
    default : false       \
  )
