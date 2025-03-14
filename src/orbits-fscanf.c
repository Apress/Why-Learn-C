#include <stdio.h>
#include <stdlib.h>

struct planet {
  double perihelion_au, aphelion_au;
};

struct planet PLANET[8];

#include "orbits-fscanf.d/read_planet_data.h"

////////// local functions ////////////////////////////////////////////////////

// local
#include "unit_test.h"
#include "util.h"

// standard
#include <float.h>
#include <math.h>
#include <unistd.h>

constexpr struct planet PLANET_EXPECTED[] = {
  {  0.31,  0.47 },     // Mercury
  {  0.72,  0.73 },     // Venus
  {  0.98,  1.02 },     // Earth
  {  1.38,  1.67 },     // Mars
  {  4.95,  5.45 },     // Jupiter
  {  9.01, 10.07 },     // Saturn
  { 18.28, 20.09 },     // Uranus
  { 29.80, 30.32 },     // Neptune
};

static char PLANET_STR[] =
  "  0.31,  0.47\n"     // Mercury
  "  0.72,  0.73\n"     // Venus
  "  0.98,  1.02\n"     // Earth
  "  1.38,  1.67\n"     // Mars
  "  4.95,  5.45\n"     // Jupiter
  "  9.01, 10.07\n"     // Saturn
  " 18.28, 20.09\n"     // Uranus
  " 29.80, 30.32\n"     // Neptune
;

static FILE* check_fmemopen( char const *buf, size_t size ) {
  FILE *const f = fmemopen( (void*)buf, size, "r" );
  if ( f == nullptr )
    perror_exit( 1 );
  return f;
}

static bool fequal( double a, double b ) {
  return fabs( a - b ) < DBL_EPSILON;
}

////////// test functions /////////////////////////////////////////////////////

int main( int, char const *const argv[] ) {
  prog_name = argv[0];

  read_planet_data( check_fmemopen( PLANET_STR, sizeof PLANET_STR - 1 ) );
  for ( unsigned p = 0; p < 8; ++p ) {
    TEST( fequal( PLANET[p].perihelion_au, PLANET_EXPECTED[p].perihelion_au ) );
    TEST( fequal( PLANET[p].aphelion_au, PLANET_EXPECTED[p].aphelion_au ) );
  }
}
