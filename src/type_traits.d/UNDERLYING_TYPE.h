#define UNDERLYING_TYPE(ENUM_TYPE)              \
  typeof( _Generic( (ENUM_TYPE)0,               \
    bool              : (bool)              0,  \
    char              : (char)              0,  \
    signed char       : (signed char)       0,  \
    short             : (short)             0,  \
    int               : (int)               0,  \
    long              : (long)              0,  \
    long long         : (long long)         0,  \
    unsigned char     : (unsigned char)     0,  \
    unsigned short    : (unsigned short)    0,  \
    unsigned int      : (unsigned int)      0,  \
    unsigned long     : (unsigned long)     0,  \
    unsigned long long: (unsigned long long)0   \
  ) )
