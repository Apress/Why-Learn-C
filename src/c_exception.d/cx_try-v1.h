#define try                                   \
  for ( struct cx_impl_try_block cx_tb = { }; \
        cx_impl_try_cond( &cx_tb ); )         \
    if ( setjmp( cx_tb.env ) == 0 )
