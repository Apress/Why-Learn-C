#define INT_MIN_EXPR(N)             \
  _Generic( (N),                    \
    bool              : 0,          \
    signed char       : SCHAR_MIN,  \
    char              : CHAR_MIN,   \
    short             : SHRT_MIN,   \
    int               : INT_MIN,    \
    long              : LONG_MIN,   \
    long long         : LLONG_MIN,  \
    unsigned char     : 0,          \
    unsigned short    : 0,          \
    unsigned int      : 0,          \
    unsigned long     : 0,          \
    unsigned long long: 0           \
  )
