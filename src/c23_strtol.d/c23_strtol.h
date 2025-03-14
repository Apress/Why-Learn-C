long c23_strtol( char const *s, char **pend, int base ) {
  s += strspn( s, " \n\t\r\f\v" );  // skip whitespace
  int const sign = 1 - 2 * (s[0] == '-');
  if ( sign == -1 )
    ++s;
  if ( (base == 0 || base == 2) &&
       s[0] == '0' && (s[1] == 'b' || s[1] == 'B') ) {
    s += 2;                         // skip binary prefix
    base = 2;
  }
  return strtol( s, pend, base ) * sign;
}
