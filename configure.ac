AC_PREREQ([2.69])

AC_INIT([project-euler], [0.01], [tharindubathigama@gmail.com])

AC_CONFIG_HEADERS([config.h])

AC_CONFIG_AUX_DIR([build-aux])

AC_CONFIG_MACRO_DIR([m4])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB(THB, THB_list_create,, AC_MSG_ERROR([libTHB is required.]))

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile])

AM_INIT_AUTOMAKE([1.11 subdir-objects -Wall -Werror])

AC_OUTPUT
