#define INT_MAX_EXPR(N)             \
  _Generic( (N),                    \
    bool              : 1,          \
    signed char       : SCHAR_MAX,  \
    char              : CHAR_MAX,   \
    short             : SHRT_MAX,   \
    int               : INT_MAX,    \
    long              : LONG_MAX,   \
    long long         : LLONG_MAX,  \
    unsigned char     : UCHAR_MAX,  \
    unsigned short    : USHRT_MAX,  \
    unsigned int      : UINT_MAX,   \
    unsigned long     : ULONG_MAX,  \
    unsigned long long: ULLONG_MAX  \
  )
