void** alloc2d( size_t esize, size_t align,
                size_t r, size_t c ) {
  // ensure &elements[0][0] is suitably aligned
  auto const ptr_size = rup2( sizeof(void*) * r, align );
  auto const row_size = esize * c;
  // allocate the row pointers followed by the elements
  void **const rows = malloc( ptr_size + r * row_size );
  char *const elements = (char*)rows + ptr_size;
  for ( size_t i = 0; i < r; ++i )
    rows[i] = &elements[ i * row_size ];
  return rows;
}
