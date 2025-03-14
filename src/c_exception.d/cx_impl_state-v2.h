enum cx_impl_state {
  CX_IMPL_INIT,         // initial state
  CX_IMPL_TRY,          // no exception thrown
  CX_IMPL_THROWN,       // exception thrown, but uncaught
  CX_IMPL_CAUGHT,       // exception caught
};
