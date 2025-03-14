#define try                                   \
  for ( struct cx_impl_try_block cx_tb = { }; \
        cx_impl_try_cond( &cx_tb ); )         \
    if ( cx_tb.state != CX_IMPL_FINALLY )     \
      if ( setjmp( cx_tb.env ) == 0 )
