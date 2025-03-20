#include "config.h"                     /* must go first */

#include <stdarg.h>
#include <stdio.h>

enum cdecl_debug { CDECL_DEBUG_NO, CDECL_DEBUG_YES };
typedef enum cdecl_debug cdecl_debug_t;

cdecl_debug_t opt_cdecl_debug;

#pragma clang diagnostic ignored "-Wformat-nonliteral"

#include "fl_print_error.d/fl_print_error.h"

///////////////////////////////////////////////////////////////////////////////

int main() {
}
