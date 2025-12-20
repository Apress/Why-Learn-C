# Process this file with autoconf to produce a configure script.

##
#       "Why Learn C"
#       configure.ac
#
#       Copyright (C) 2025  Paul J. Lucas
#
#       This program is free software: you can redistribute it and/or modify
#       it under the terms of the GNU General Public License as published by
#       the Free Software Foundation, either version 3 of the License, or
#       (at your option) any later version.
#
#       This program is distributed in the hope that it will be useful,
#       but WITHOUT ANY WARRANTY; without even the implied warranty of
#       MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#       GNU General Public License for more details.
#
#       You should have received a copy of the GNU General Public License
#       along with this program.  If not, see <http://www.gnu.org/licenses/>.
##

AC_PREREQ([2.69])
AC_INIT([Why_Learn_C], [1.1], [https://github.com/Apress/Why-Learn-C/issues],,[https://github.com/Apress/Why-Learn-C])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

# Checks for programs.
AC_LANG(C)
AC_PROG_CC
gl_EARLY
AC_PROG_INSTALL
WHY_C_CFLAGS="-std=c23"

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([inttypes.h])
AC_CHECK_HEADERS([limits.h])
AC_CHECK_HEADERS([stddef.h])
AC_CHECK_HEADERS([sysexits.h])
AC_HEADER_ASSERT
gl_INIT

# Checks for typedefs, structures, and compiler characteristics.
CFLAGS_ORIG="$CFLAGS"
CFLAGS="$CFLAGS $WHY_C_CFLAGS"
PJL_MUST_COMPILE([alignas],[],[alignas(int) char x;])
PJL_MUST_COMPILE([auto],[],[auto x = 0;])
PJL_MUST_COMPILE([bool],[],[bool x = false;])
PJL_COMPILE([constexpr],[],[constexpr int x = 0;])
if test "$pjl_cv_constexpr" = "no"; then
  AC_DEFINE([constexpr],[const],[Define to const.])
fi
PJL_MUST_COMPILE([digit_separators], [], [int x = 1'000;])
# Balance ' on previous line to resume proper vim syntax highlighting.
PJL_MUST_COMPILE([empty_aggregate_initialization], [], [int a[2] = { };])
PJL_MUST_COMPILE([fixed_type_enumerations], [], [enum E : char { E1 };])
PJL_MUST_COMPILE([function_unnamed_parameters],[void f( int ) { }], [])
PJL_MUST_COMPILE([noreturn],
  [[#include <stdlib.h>
  [[noreturn]] void f() { exit(0); }]],
  [])
PJL_MUST_COMPILE([nullptr],[],[void *p = nullptr;])
PJL_MUST_COMPILE([static_assert],[],[static_assert(1,"");])
PJL_MUST_COMPILE([thread_local],[],[static thread_local int x;])
PJL_MUST_COMPILE([typeof],[],[typeof(0) x;])
PJL_MUST_COMPILE([typeof_unqual],[],[typeof_unqual(0) x;])
PJL_MUST_COMPILE([no_named_parameter_variadic_functions],[void f(...) { }],[])
PJL_MUST_COMPILE([c23_va_start],
  [#include <stdarg.h>
  void c23_va_start(...) { va_list args; va_start( args ); }],
  [c23_va_start();]
)
PJL_MUST_COMPILE([__VA_OPT__],
  [#define VA_OPT_TEST(...) __VA_OPT__(int) __VA_ARGS__
  ],
  [int x1 = VA_OPT_TEST() 1; VA_OPT_TEST(x2 = 2);]
)
CFLAGS="$CFLAGS_ORIG"

PJL_COMPILE([__STDC_NO_THREADS__],[],[int x = __STDC_NO_THREADS__;])
PJL_COMPILE([pthread_mutex_timedlock],
  [#include <pthread.h>
  ],
  [pthread_mutex_timedlock( NULL, NULL );]
)

# Checks for library functions.
AC_SEARCH_LIBS([call_once],[stdthreads])

# Makefile conditionals.
AM_CONDITIONAL([HAVE___STDC_NO_THREADS__],
               [test x$pjl_cv___STDC_NO_THREADS__ = xyes])

# Compiler warnings.
AC_SUBST([WHY_C_CFLAGS])
AX_CFLAGS_WARN_ALL([WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wcast-align], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wcast-function-type], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wcomma], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wconditional-type-mismatch], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wconditional-uninitialized], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wconversion], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wduplicate-enum], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wembedded-directive], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wenum-enum-conversion], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wenum-float-conversion], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wextra], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wfloat-equal], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wfor-loop-analysis], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wformat-signedness], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wformat-type-confusion], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wformat=2], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Widiomatic-parentheses], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wimplicit-fallthrough], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wlogical-op-parentheses], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wmisleading-indentation], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wnewline-eof], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wno-cast-function-type-strict], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wno-clobbered], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wno-dangling-pointer], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wno-empty-body], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wno-reserved-macro-identifier], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wno-shadow], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wno-unknown-pragmas], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wno-unused-value], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wredundant-decls], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wreserved-identifier], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wshift-sign-overflow], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wshorten-64-to-32], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wsign-compare], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wsign-conversion], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wsometimes-uninitialized], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wstring-conversion], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wtautological-compare], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wtautological-type-limit-compare], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wuninitialized], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wunreachable-code-break], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wunreachable-code-return], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wunreachable-code], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wunused], [WHY_C_CFLAGS])
PJL_CHECK_COMPILE_FLAG([-Wwrite-strings], [WHY_C_CFLAGS])

# Generate files.
AH_TOP([#ifndef Why_Learn_C_config_H
#define Why_Learn_C_config_H])
AH_BOTTOM([#endif /* Why_Learn_C_config_H */])
AC_CONFIG_HEADERS([src/config.h])
AC_CONFIG_FILES([
  Makefile
  lib/Makefile
  src/Makefile
])
AC_OUTPUT

# vim:set et sw=2 ts=2:
