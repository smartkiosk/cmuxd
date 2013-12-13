AC_INIT([cmux], [1.0], [smartkiosk@roundlake.ru])
AC_CONFIG_MACRO_DIR([m4])
AC_PROG_CXX
AM_PROG_CC_C_O
AM_INIT_AUTOMAKE
LT_INIT

AC_CHECK_MEMBER([struct sockaddr_un.sun_len],
    [AC_DEFINE(HAVE_SOCKADDR_SUN_LEN,1,[Have the sockaddr_un.sun_len member.])],
    [],
    [ #include <sys/types.h>
      #include <sys/un.h>
    ])

AC_CHECK_HEADERS([util.h pty.h])

AC_CHECK_MEMBER([struct ucred.pid], [AC_DEFINE(HAVE_STRUCT_UCRED,1,[Have struct ucred.])],
    [],
    [ #include <sys/types.h>
      #include <sys/un.h>
    ])

AC_CHECK_MEMBER([struct xucred.cr_uid], [AC_DEFINE(HAVE_STRUCT_XUCRED,1,[Have struct xucred.])],
    [],
    [ #include <sys/ucred.h>
    ])

AC_OUTPUT([Makefile
           include/Makefile
           libcmux/Makefile
           cmuxcontrold/Makefile
           etc/Makefile])
