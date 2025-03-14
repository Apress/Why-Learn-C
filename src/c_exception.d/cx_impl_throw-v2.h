[[noreturn]] void cx_impl_do_throw() {
  if ( cx_impl_try_block_head == nullptr )
    cx_terminate();
  cx_impl_try_block_head->state = CX_IMPL_THROWN;
  cx_impl_try_block_head->thrown_xid = cx_impl_exception.thrown_xid;
  longjmp( cx_impl_try_block_head->env, 1 );
}

[[noreturn]] void cx_impl_throw( char const *file,
                                 int line, int xid ) {
  cx_impl_exception =
    (struct cx_exception){ file, line, xid };
  cx_impl_do_throw();
}
