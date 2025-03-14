constexpr unsigned EX_FILE_IO_ERROR  = 0x0101;
constexpr unsigned EX_FILE_NOT_FOUND = 0x0102;

void read_file( char const *path ) {
  switch ( setjmp( env ) ) {
    case 0:
      read_file( path );
      break;
    case EX_FILE_IO_ERROR:
      // ...
      break;
    case EX_FILE_NOT_FOUND:
      // ...
      break;
  }
}
