enum token_kind {
  TOKEN_NONE,
  TOKEN_INT,
  TOKEN_FLOAT,
  TOKEN_CHAR,
  TOKEN_STR
};

struct token {
  enum token_kind kind;
  union {
    int     i;
    double  f;
    char    c;
    char   *s;
  };
};
