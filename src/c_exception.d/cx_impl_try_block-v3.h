struct cx_impl_try_block {
  jmp_buf                   env;
  struct cx_impl_try_block *parent;
  enum cx_impl_state        state;
  int                       thrown_xid;
  int                       caught_xid;
};
