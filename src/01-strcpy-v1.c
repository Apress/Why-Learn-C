char* strcpy( char *dst, char const *src ) {
  char *const dst_orig = dst;
  while ( true ) {
    *dst = *src;
    if ( *dst == '\0' )
      return dst_orig;
    ++dst;
    ++src;
  }
}

///////////////////////////////////////////////////////////////////////////////

int main() {
}
