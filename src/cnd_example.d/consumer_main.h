static bool  work_avail;
static cnd_t work_avail_cnd;
static mtx_t work_avail_mtx;

static int consumer_main( void* ) {
  while ( !load_bool_mtx( &shutdown, &shutdown_mtx ) ) {
    mtx_lock( &work_avail_mtx );
    while ( !work_avail )
      cnd_wait( &work_avail_cnd, &work_avail_mtx );
    work_avail = false;
    mtx_unlock( &work_avail_mtx );
    // ... do work ...
  }
  return 0;
}
