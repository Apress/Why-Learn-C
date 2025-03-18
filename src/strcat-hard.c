#include <stdio.h>
#include <string.h>

int main() {
  char greeting[13] = "hello";  // 5 + 7 + 1 = 13
  strcat( greeting, ", world" );
  puts( greeting );
}
