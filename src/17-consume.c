#include "config.h"                     /* must go first */

#include <stddef.h>
#include <stdlib.h>

#include "islist.d/struct.h"
#include "islist.d/functions.h"

#include <stdatomic.h>

struct islist *work_list;
#include "consume.d/work_avail.h"

static int producer_main( void* ) {
  char *path = nullptr;
# include "consume.d/producer.h"
  return 0;
}

static int consumer_main( void* ) {
# include "consume.d/consumer.h"
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
