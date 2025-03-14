#define IS_FLOATING_POINT_EXPR(E) \
  _Generic( (E),                  \
    float       : true,           \
    double      : true,           \
    long double : true,           \
    default     : false           \
  )
