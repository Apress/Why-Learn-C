#include "stdc_threads.h"

#include "handy/VA_ARGS_COUNT.h"
#include "mtx_lockall.d/mtx_lockall.h"
#include "mtx_lockall.d/mtx_lockall-macro.h"

////////// local functions ////////////////////////////////////////////////////

int mtx_unlockall( size_t n, mtx_t *mtx[n] ) {
  int status = thrd_success;
  while ( n > 0 ) {
    if ( mtx_unlock( mtx[--n] ) == thrd_error )
      status = thrd_error;
  }
  return status;
}

#define mtx_unlockall(...) \
  mtx_unlockall( VA_ARGS_COUNT( __VA_ARGS__ ), (mtx_t*[]){ __VA_ARGS__ } )

///////////////////////////////////////////////////////////////////////////////

int main() {
  mtx_t m1, m2, m3;
  mtx_init( &m1, mtx_plain );
  mtx_init( &m2, mtx_plain );
  mtx_init( &m3, mtx_plain );

  mtx_lockall( &m1, &m2, &m3 );
  mtx_unlockall( &m1, &m2, &m3 );

  mtx_destroy( &m3 );
  mtx_destroy( &m2 );
  mtx_destroy( &m1 );
}
