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

#pragma clang diagnostic ignored "-Wswitch"

#include "token-v2.d/token.h"

///////////////////////////////////////////////////////////////////////////////

int main() {
  [[maybe_unused]] struct token t = {
    .kind = TOKEN_INT,
    .print_int = &print_int,
    .print_float = &print_float,
    .print_char = &print_char,
    .print_str = &print_str,
  };
}
