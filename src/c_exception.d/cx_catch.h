#define catch(XID) \
  else if ( cx_impl_catch( (XID), &cx_tb ) )
