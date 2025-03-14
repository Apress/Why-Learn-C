bool cx_impl_try_cond( struct cx_impl_try_block *tb ) {
  switch ( tb->state ) {
    case CX_IMPL_INIT:
      tb->parent = cx_impl_try_block_head;
      cx_impl_try_block_head = tb;
      tb->state = CX_IMPL_TRY;
      return true;
    case CX_IMPL_TRY:
      cx_impl_try_block_head = tb->parent;
      return false;
  }
}
