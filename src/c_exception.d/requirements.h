void read_file( char const *path ) {
  auto f = fopen( path, "r" );
  if ( f == nullptr )
    throw ( EX_FILE_NOT_FOUND );
  // ...
}

int main() {
  try {
    read_file( ".config" );
  }
  catch ( EX_FILE_NOT_FOUND ) {
    // ...
  }
}
