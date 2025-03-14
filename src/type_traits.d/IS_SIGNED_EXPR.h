#define IS_SIGNED_EXPR(E)               \
  _Generic( (E),                        \
    bool       : false,                 \
    char       : IS_SIGNED_TYPE(char),  \
    signed char: true,                  \
    short      : true,                  \
    int        : true,                  \
    long       : true,                  \
    long long  : true,                  \
    default    : false                  \
  )
