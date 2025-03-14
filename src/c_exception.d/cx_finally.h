#define finally   else /* setjmp() != 0 */; \
                  else /* cx_tb.state == CX_IMPL_FINALLY */
