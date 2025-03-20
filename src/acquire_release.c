#include "config.h"                     /* must go first */

#include <stdatomic.h>
#include <stddef.h>
#include <stdlib.h>

#include "islist.d/struct.h"
#include "islist.d/functions.h"
#include "acquire_release.d/work.h"

static int producer_main( void* ) {
  char *path = nullptr;
# include "acquire_release.d/producer.h"
  return 0;
}

static int consumer_main( void* ) {
# include "acquire_release.d/consumer.h"
  (void)path;
  return 0;
}

///////////////////////////////////////////////////////////////////////////////

void suppress_unused_function_warnings() {
  producer_main( nullptr );
  consumer_main( nullptr );
}

int main() {
}
