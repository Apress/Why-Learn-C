#define IS_SAME_TYPE(T,U)               \
  _Generic( (typeof_unqual(T)*)nullptr, \
    typeof_unqual(U)* : true,           \
    default           : false           \
  )
