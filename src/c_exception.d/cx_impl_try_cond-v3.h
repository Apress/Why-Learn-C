bool cx_impl_try_cond( struct cx_impl_try_block *tb ) {
  switch ( tb->state ) {
    case CX_IMPL_INIT:
      tb->parent = cx_impl_try_block_head;
      cx_impl_try_block_head = tb;
      tb->state = CX_IMPL_TRY;
      return true;
    case CX_IMPL_CAUGHT:
      tb->thrown_xid = 0;       // reset for finally case
      [[fallthrough]];
    case CX_IMPL_TRY:
    case CX_IMPL_THROWN:
      tb->state = CX_IMPL_FINALLY;
      return true;
    case CX_IMPL_FINALLY:
      cx_impl_try_block_head = tb->parent;
      if ( tb->thrown_xid != 0 )
        cx_impl_do_throw();     // rethrow exception
      cx_impl_exception = (struct cx_exception){ };
      return false;
  }
}
