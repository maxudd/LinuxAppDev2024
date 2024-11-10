#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.71])
AC_INIT([rhasher], [2.28], [a@a.org])
AM_INIT_AUTOMAKE([foreign subdir-objects])
AC_CONFIG_FILES([Makefile])
AC_CONFIG_SRCDIR([rhasher.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB([rhash],[rhash_library_init],[],[AC_MSG_ERROR([Rhash is missing])])

# check for readline
# AC_ARG_WITH([readline],
#     [AS_HELP_STRING([--with-readline], [Use readline for input])],
#     [use_readline=$withval],
#     [use_readline=no])

# if test "x$use_readline" = "xyes"; then
#     AC_CHECK_LIB([readline], [readline], [have_readline=yes], [have_readline=no])
#     if test "x$have_readline" = "xno"; then
#         AC_MSG_ERROR([Readline library not found.])
#     fi
# else
#     AC_DEFINE([HAVE_LIBREADLINE], [1], [Define to use getline instead of readline])
# fi
AC_ARG_ENABLE([readline],
    [AS_HELP_STRING([--enable-readline], [Use readline for input])],
    [AC_CHECK_LIB(
        [readline],
        [readline],
        [AC_DEFINE(HAVE_LIBREADLINE,[1],[Readline support])],
        [AC_MSG_ERROR([Readline not found])]
    )],
    []
)

# Checks for header files.
AC_CHECK_HEADERS([string.h])
AC_CHECK_HEADERS([rhash.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

AC_OUTPUT
