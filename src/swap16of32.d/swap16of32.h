uint32_t swap16of32( uint32_t n ) {
  union {
    uint32_t u32;
    uint16_t u16[2];
  } u = { n };
  auto const t16 = u.u16[0];
  u.u16[0] = u.u16[1];
  u.u16[1] = t16;
  return u.u32;
}
