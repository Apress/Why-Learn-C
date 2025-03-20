#include <sys/stat.h>   // for lstat(2)

static char const* mode_str( mode_t mode ) {
  if ( S_ISREG ( mode ) ) return "file";
  if ( S_ISDIR ( mode ) ) return "directory";
  if ( S_ISLNK ( mode ) ) return "link";
  if ( S_ISBLK ( mode ) ) return "block";
  if ( S_ISCHR ( mode ) ) return "character";
  if ( S_ISFIFO( mode ) ) return "named pipe";
  if ( S_ISSOCK( mode ) ) return "socket";
  return "unknown";
}

int main( int argc, char const *const argv[] ) {
  if ( --argc != 1 )
    usage( argv[0] );
  struct stat st;
  if ( lstat( argv[1], &st ) == -1 )
    perror_exit( argv[0] );
  printf( "%s %s %llu\n", argv[1], mode_str( st.st_mode ),
          (unsigned long long)st.st_size );
}
