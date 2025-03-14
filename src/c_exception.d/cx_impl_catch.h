bool cx_impl_catch( int catch_xid,
                    struct cx_impl_try_block *tb ) {
  if ( tb->caught_xid == tb->thrown_xid )
    return false;
  if ( tb->thrown_xid != catch_xid )
    return false;
  tb->state = CX_IMPL_CAUGHT;
  tb->caught_xid = tb->thrown_xid;
  return true;
}
