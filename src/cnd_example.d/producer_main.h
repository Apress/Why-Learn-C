static int producer_main( void* ) {
  while ( !load_bool_mtx( &shutdown, &shutdown_mtx ) ) {
    // ... prepare work ...
    mtx_lock( &work_avail_mtx );
    work_avail = true;
    cnd_signal( &work_avail_cnd );
    mtx_unlock( &work_avail_mtx );
  }
  return 0;
}
