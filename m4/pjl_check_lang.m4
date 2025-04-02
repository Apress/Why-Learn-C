##
# SYNOPSIS
#
#     PJL_CHECK_LANG(label, include(s), program)
#
# DESCRIPTION
#
#     Shorthand for calling AC_COMPILE_IFELSE() and printing an error message
#     if the compile fails.
#
# PARAMETERS
#
#     $1  Label.
#     $2  #include(s), if any.
#     $3  Code snippet to compile.
#
# LICENSE
#
#     Copyright (C) 2025  Paul J. Lucas
#
#     This program is free software: you can redistribute it and/or modify
#     it under the terms of the GNU General Public License as published by
#     the Free Software Foundation, either version 3 of the License, or
#     (at your option) any later version.
#
#     This program is distributed in the hope that it will be useful,
#     but WITHOUT ANY WARRANTY; without even the implied warranty of
#     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#     GNU General Public License for more details.
#
#     You should have received a copy of the GNU General Public License
#     along with this program.  If not, see <http://www.gnu.org/licenses/>.
##

#serial 1

AC_DEFUN([PJL_CHECK_LANG], [
  AC_REQUIRE([AC_COMPILE_IFELSE])
  AC_CACHE_CHECK([whether C compiler supports $1], [pjl_cv_check_lang],
    [AC_COMPILE_IFELSE(
      [AC_LANG_PROGRAM([$2], [$3])],
      [pjl_cv_check_lang=yes],
      [pjl_cv_check_lang=no]
    )
  ])
  if test "$pjl_cv_check_lang" = "no"; then
    AC_MSG_ERROR(["$1" not supported by C compiler])
  fi
])

dnl vim:set et sw=2 ts=2:
