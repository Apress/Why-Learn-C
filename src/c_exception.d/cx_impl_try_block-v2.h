enum cx_impl_state {
  CX_IMPL_INIT,                     // initial state
  CX_IMPL_TRY,                      // no exception thrown
};

struct cx_impl_try_block {
  jmp_buf                   env;
  struct cx_impl_try_block *parent;
  enum cx_impl_state        state;  // new exception state
};
