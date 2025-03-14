#define IS_UNSIGNED_EXPR(E)                     \
  _Generic( (E),                                \
    bool              : true,                   \
    char              : IS_UNSIGNED_TYPE(char), \
    unsigned char     : true,                   \
    unsigned short    : true,                   \
    unsigned int      : true,                   \
    unsigned long     : true,                   \
    unsigned long long: true,                   \
    default           : false                   \
  )
