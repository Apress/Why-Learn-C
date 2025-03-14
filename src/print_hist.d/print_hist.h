void print_hist( unsigned nvals, unsigned const vals[],
                 unsigned buckets, char marker ) {
  unsigned hist[ buckets + 1 ] = { };
  for ( unsigned i = 0; i < nvals; ++i ) {
    if ( vals[i] <= buckets )
      ++hist[ vals[i] ];
  }
  for ( unsigned b = 0; b <= buckets; ++b ) {
    auto h = hist[ b ];
    if ( h == 0 )
      continue;
    printf( "%3u: ", b );
    while ( h-- > 0 )
      putchar( marker );
    putchar( '\n' );
  }
}
