enum token_kind {
  TOKEN_NONE,
  TOKEN_INT,
  TOKEN_FLOAT,
  TOKEN_CHAR,
  TOKEN_STR
};

void print_int( long ) {
}

void print_float( double ) {
}

void print_char( char ) {
}

void print_str( char const* ) {
}

struct token_vtbl {
  void (*print_int)( long );
  void (*print_float)( double );
  void (*print_char)( char );
  void (*print_str)( char const* );
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

static struct token_vtbl const TOKEN_VTBL_DEFAULT = {
  &print_int, &print_float, &print_char, &print_str
};

#pragma clang diagnostic ignored "-Wswitch"

#include "itoken.d/itoken.h"

///////////////////////////////////////////////////////////////////////////////

int main() {
  struct token token;
  [[maybe_unused]]
  struct itoken itoken = {
    .vptr = &TOKEN_VTBL_DEFAULT, .token = &token
  };
}
