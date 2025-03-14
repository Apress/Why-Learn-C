[[noreturn]] static void cx_terminate() {
  fprintf( stderr,
    "%s:%d: unhandled exception %d (0x%X)\n",
    cx_impl_exception.thrown_file, cx_impl_exception.thrown_line,
    cx_impl_exception.thrown_xid,
    (unsigned)cx_impl_exception.thrown_xid
  );
  abort();
}
