int main() {
  struct string str = { };
  string_puts( &str, "hello" );
  string_puts( &str, ", world" );
  puts( str.contents );
  string_cleanup( &str );
}
