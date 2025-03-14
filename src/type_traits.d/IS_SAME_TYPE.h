#define IS_SAME_TYPE(T,U)   \
  _Generic( *(T*)nullptr,   \
    typeof_unqual(U): true, \
    default         : false \
  )
