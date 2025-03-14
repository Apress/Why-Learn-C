constexpr uint64_t FNV1A64_INIT  = 14695981039346656037UL;
constexpr uint64_t FNV1A64_PRIME = 1099511628211UL;

uint64_t fnv1a64_mem( uint64_t hash, void const *data,
                      size_t n ) {
  for ( size_t i = 0; i < n; ++i )
    hash = FNV1A64_PRIME *
           (hash ^ ((uint8_t const*)data)[i]);
  return hash;
}
