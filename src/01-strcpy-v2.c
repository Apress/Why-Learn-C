char* strcpy( char *dst, char const *src ) {
  char *const dst_orig = dst;
  while ( (*dst++ = *src++) )
    ;
  return dst_orig;
}

///////////////////////////////////////////////////////////////////////////////

int main() {
}
