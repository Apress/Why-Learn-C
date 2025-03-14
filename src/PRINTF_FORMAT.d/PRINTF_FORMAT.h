#define PRINTF_FORMAT(T)                              \
  _Generic( (T),                                      \
    bool        : "%d",   char              : "%c",   \
    signed char : "%hhd", unsigned char     : "%hhu", \
    short       : "%hd",  unsigned short    : "%hu",  \
    int         : "%d",   unsigned int      : "%u",   \
    long        : "%ld",  unsigned long     : "%lu",  \
    long long   : "%lld", unsigned long long: "%llu", \
    float       : "%f",                               \
    double      : "%f",   long double       : "%Lf",  \
    char*       : "%s",   char const*       : "%s",   \
    wchar_t*    : "%ls",  wchar_t const*    : "%ls",  \
    void*       : "%p",   void const*       : "%p"    \
  )

#define PRINTF(X)   printf( PRINTF_FORMAT( (X) ), (X) )
