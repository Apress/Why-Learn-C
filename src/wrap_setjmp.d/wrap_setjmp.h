int wrap_setjmp( jmp_buf env ) {  // don't wrap setjmp
  if ( setjmp( env ) == 0 )
    return 0;
  return 1;
}

void read_file( char const *path ) {
  if ( wrap_setjmp( env ) == 0 ) {
    // ...
