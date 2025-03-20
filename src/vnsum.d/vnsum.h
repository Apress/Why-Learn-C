#include <stdarg.h>

int vnsum( unsigned n, ... ) {
  va_list args;
  va_start( args );
  int sum = 0;
  while ( n-- > 0 )
    sum += va_arg( args, int );
  va_end( args );
  return sum;
}
