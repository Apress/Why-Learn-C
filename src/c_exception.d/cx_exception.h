struct cx_exception {
  char const *thrown_file;  // thrown from this file
  int         thrown_line;  // thrown from this line
  int         thrown_xid;   // thrown exception ID
};

static thread_local struct cx_exception cx_impl_exception;
