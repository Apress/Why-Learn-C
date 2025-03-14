#define DECL_UNUSED(T,N) \
  alignas(T) char UNIQUE_NAME(unused)[ sizeof(T) * (N) ]
