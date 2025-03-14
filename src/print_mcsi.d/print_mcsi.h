static void print_csi( size_t n, int const vals[n] ) {
  if ( n == 0 )
    return;
  printf( "%d", vals[0] );
  for ( size_t i = 1; i < n; ++i )
    printf( ", %d", vals[i] );
}

void print_mcsi( size_t m, size_t n,
                 int const vals[m][n] ) {
  for ( size_t j = 0; j < m; ++j ) {
    print_csi( n, vals[j] );
    putchar( '\n' );
  }
}
