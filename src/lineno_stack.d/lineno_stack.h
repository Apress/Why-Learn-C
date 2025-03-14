static unsigned lineno_stack[64];
static int      lineno_stack_top = -1;

void lineno_stack_push( unsigned lineno ) {
  ++lineno_stack_top;
  assert( lineno_stack_top < ARRAY_SIZE( lineno_stack ) );
  lineno_stack[ lineno_stack_top ] = lineno;
}
