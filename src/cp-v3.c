#include <stdio.h>
#include <stdlib.h>

constexpr size_t BUF_SIZE = 4096;

int main() {
  char    buf[ BUF_SIZE ];
  size_t  bytes;

  do {
    bytes = fread( buf, 1, BUF_SIZE, stdin );
    if ( ferror( stdin ) )
      goto error;
    if ( fwrite( buf, 1, bytes, stdout ) < bytes )
      goto error;
  } while ( bytes == BUF_SIZE );
  return EXIT_SUCCESS;

error:
  perror( "copy" );
  return EXIT_FAILURE;
}
