#include "config.h"                     /* must go first */

#include <string.h>

#pragma clang diagnostic ignored "-Wcast-function-type-strict"
#pragma clang diagnostic ignored "-Wincompatible-pointer-types-discards-qualifiers"

#include "user.d/struct-cmp.h"

struct slist {
  struct slist *next;
  void *data;
};

#include "user.d/slist_find.h"
#include "user.d/find_root.h"

///////////////////////////////////////////////////////////////////////////////

int main() {
}
