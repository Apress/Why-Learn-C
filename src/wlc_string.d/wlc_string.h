#ifndef wlc_string_H
#define wlc_string_H

#include <stddef.h> /* for size_t */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct string {
  char   *contents; // pointer to actual contents
  size_t  len;      // length (not including null at end)
};

void string_puts( struct string *str, char const *s );
void string_cleanup( struct string *str );

#ifdef __cplusplus
} // extern "C"
#endif /* __cplusplus */

#endif /* wlc_string_H */
