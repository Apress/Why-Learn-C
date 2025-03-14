#define STATIC_IF(EXPR,THEN,ELSE)     \
  _Generic( &(char[1 + !!(EXPR)]){ }, \
    char (*)[2]: (THEN),              \
    char (*)[1]: (ELSE)               \
  )
