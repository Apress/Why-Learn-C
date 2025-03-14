void print_csi( size_t n, int const *vals ) {
  if ( n == 0 )
    return;
  printf( "%d", vals[0] );
  for ( size_t i = 1; i < n; ++i )
    printf( ", %d", vals[i] );
}
