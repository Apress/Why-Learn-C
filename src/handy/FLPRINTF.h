#define FLFPRINTF(FOUT, FORMAT, ...)                    \
  fprintf( (FOUT), "%s:%d: " FORMAT, __FILE__, __LINE__ \
           __VA_OPT__(,) __VA_ARGS__ )

#define FLPRINTF(FORMAT, ...) \
  FLFPRINTF( stdout, FORMAT __VA_OPT__(,) __VA_ARGS__ )
