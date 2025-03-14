#define IS_C_STR_EXPR(E)  \
  _Generic( (E),          \
    char*       : true,   \
    char const* : true,   \
    default     : false   \
  )
