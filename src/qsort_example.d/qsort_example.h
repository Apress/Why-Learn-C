int strcmp_for_qsort( void const *ips, void const *jps ) {
  return strcmp( *(char const**)ips, *(char const**)jps );
}

void sort_colors() {
  qsort( COLORS, sizeof COLORS / sizeof COLORS[0],
         sizeof COLORS[0], &strcmp_for_qsort );
}
