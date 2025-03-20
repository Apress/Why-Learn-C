#include <math.h>       // for sqrt()
#include <stdio.h>

constexpr double PLANET_AU[][2] = {
  {  0.31,  0.47 },     // Mercury
  {  0.72,  0.73 },     // Venus
  {  0.98,  1.02 },     // Earth
  {  1.38,  1.67 },     // Mars
  {  4.95,  5.45 },     // Jupiter
  {  9.01, 10.07 },     // Saturn
  { 18.28, 20.09 },     // Uranus
  { 29.80, 30.32 },     // Neptune
};

double orbital_period( unsigned p ) {
  auto const a = (PLANET_AU[p][0] + PLANET_AU[p][1]) / 2;
  return sqrt( a * a * a );
}

int main() {
  for ( unsigned p = 0; p < 8; ++p ) {
    auto const period = orbital_period( p );
    if ( period < 1.0 ) // < 1 Earth year: print in days
      printf( "%u %6.2fd\n", p, period * 365.25 );
    else
      printf( "%u %6.2fy\n", p, period );
  }
}
