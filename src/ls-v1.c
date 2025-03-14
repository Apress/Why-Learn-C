#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////////////////




// line 10
#include <dirent.h>

static bool is_dot_or_dot_dot( char const *path ) {
  return path[0] == '.' && (path[1] == '\0' ||
        (path[1] == '.' &&  path[2] == '\0'));
}

int main( int, char const *const argv[] ) {
  DIR *const dir = opendir( "." );
  if ( dir == nullptr ) {
    fprintf( stderr, "%s: could not open\n", argv[0] );
    exit( 1 );
  }
  for ( struct dirent const *ent;
        (ent = readdir( dir )) != nullptr; ) {
    if ( !is_dot_or_dot_dot( ent->d_name ) )
      puts( ent->d_name );
  }
  closedir( dir );
}
