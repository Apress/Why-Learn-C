#define INTERNAL_ERROR(FORMAT, ...)               \
  BLOCK(                                          \
    FLFPRINTF( stderr, "internal error: " FORMAT  \
               __VA_OPT__(,) __VA_ARGS__ );       \
    exit( EXIT_INTERNAL );                        \
  )
