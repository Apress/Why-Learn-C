static tss_t buf_tss;

static int thread_main( void* ) {
  tss_set( buf_tss, malloc( 1024 ) );
  // ...
  return 0;
}

int main() {
  // ...
  if ( tss_create( &buf_tss, &free ) != thrd_success ) {
    FLFPRINTF( stderr, "tss_create failed\n" );
    return 0;
  }
  // ... create & join threads ...
  tss_delete( buf_tss );
}
