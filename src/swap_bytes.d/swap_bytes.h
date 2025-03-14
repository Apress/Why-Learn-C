uint16_t swap16( uint16_t n ) {
  return (uint16_t)((n >> 8) | (n << 8));
}

uint32_t swap32( uint32_t n ) {
  return (uint32_t) swap16( (uint16_t)(n >> 16) )
       | (uint32_t)(swap16( (uint16_t) n        ) << 16);
}
