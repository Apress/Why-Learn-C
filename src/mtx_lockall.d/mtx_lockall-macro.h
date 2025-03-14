#define mtx_lockall(...)                      \
  mtx_lockall( VA_ARGS_COUNT( __VA_ARGS__ ),  \
               (mtx_t*[]){ __VA_ARGS__ } )
