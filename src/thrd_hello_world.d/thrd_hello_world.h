static int print_msg( void *thread_data ) {
  char const *const msg = thread_data;
  fputs( msg, stdout );
  return 0;
}

int main() {
  thrd_t t;
  thrd_create( &t, &print_msg, (void*)"hello, world\n" );
  // ...
  thrd_join( t, /*pretval=*/nullptr );
}
