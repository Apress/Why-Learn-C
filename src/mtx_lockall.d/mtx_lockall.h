int mtx_lockall( size_t n, mtx_t *mtx[n] ) {
  if ( n == 0 )
    return thrd_success;
  int status = thrd_success;
  do {
    if ( mtx_lock( mtx[0] ) == thrd_error )
      break;
    for ( size_t n_lock = 1; n_lock < n; ++n_lock ) {
      status = mtx_trylock( mtx[n_lock] );
      if ( status != thrd_success ) {
        while ( n_lock > 0 ) {
          if ( mtx_unlock( mtx[--n_lock] ) == thrd_error )
            status = thrd_error;
        }
        goto try_again;
      }
    }
    return thrd_success;

try_again:
    thrd_yield();
  } while ( status != thrd_error );
  return thrd_error;
}
