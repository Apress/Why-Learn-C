void read_planet_data( FILE *f ) {
  for ( unsigned p = 0; p < 8; ++p ) {
    if ( fscanf( f, "%lf,%lf\n",
                 &PLANET[p].perihelion_au,
                 &PLANET[p].aphelion_au ) != 2 ) {
      fprintf( stderr, "data error for planet %u\n", p );
      exit( 1 );
    }
  }
}
