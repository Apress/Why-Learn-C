#include <stdio.h>
#include <string.h>

int main() {
  char greeting[12] = "hello";  // 5 + 6 + 1 = 12
  strcat( greeting, " world" );
  puts( greeting );
}
