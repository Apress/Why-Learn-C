struct cx_impl_try_block {
  jmp_buf                   env;
  struct cx_impl_try_block *parent; // parent, if any
};

static thread_local
struct cx_impl_try_block *cx_impl_try_block_head;
