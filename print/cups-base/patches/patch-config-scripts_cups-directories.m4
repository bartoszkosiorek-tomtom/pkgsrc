$NetBSD: patch-config-scripts_cups-directories.m4,v 1.2 2020/05/26 08:36:56 triaxx Exp $

The '$' while loops expand the variables as long as possible so that no
references to other variables occur. This is necessary because fontpath
may be "${exec_prefix}", which itself may be "${prefix}", and so on. I
don't know how many levels of indirection are possible, therefore the
loop.

I'm also sure that this is not the Right Way to fix it, but at least it
works.

--- config-scripts/cups-directories.m4.orig	2017-06-30 15:44:38.000000000 +0000
+++ config-scripts/cups-directories.m4
@@ -97,7 +97,7 @@ dnl Fix "libdir" variable...
 if test "$libdir" = "\${exec_prefix}/lib"; then
 	case "$host_os_name" in
 		linux*)
-			if test -d /usr/lib64 -a ! -d /usr/lib64/fakeroot; then
+			if test -d /usr/lib64 -a ! -d /usr/lib64/fakeroot && false; then
 				libdir="$exec_prefix/lib64"
 			fi
 			;;
@@ -174,7 +174,15 @@ AC_SUBST(CUPS_CACHEDIR)
 
 # Data files
 CUPS_DATADIR="$datadir/cups"
-AC_DEFINE_UNQUOTED(CUPS_DATADIR, "$datadir/cups")
+done=no
+while test $done = no; do
+	case "$CUPS_DATADIR" in
+	*'$'*) eval "CUPS_DATADIR=$CUPS_DATADIR";;
+	*) done=yes;;
+	esac
+done
+
+AC_DEFINE_UNQUOTED(CUPS_DATADIR, "$CUPS_DATADIR")
 AC_SUBST(CUPS_DATADIR)
 
 # Icon directory
@@ -183,7 +191,11 @@ AC_ARG_WITH(icondir, [  --with-icondir  
 if test "x$icondir" = x -a -d /usr/share/icons; then
 	ICONDIR="/usr/share/icons"
 else
-	ICONDIR="$icondir"
+	if test "x$icondir" = xno; then
+		ICONDIR=""
+	else
+		ICONDIR="$icondir"
+	fi
 fi
 
 AC_SUBST(ICONDIR)
@@ -194,7 +202,11 @@ AC_ARG_WITH(menudir, [  --with-menudir  
 if test "x$menudir" = x -a -d /usr/share/applications; then
 	MENUDIR="/usr/share/applications"
 else
-	MENUDIR="$menudir"
+	if test "x$menudir" = xno; then
+		MENUDIR=""
+	else
+		MENUDIR="$menudir"
+	fi
 fi
 
 AC_SUBST(MENUDIR)
@@ -209,7 +226,15 @@ else
 	CUPS_DOCROOT="$docdir"
 fi
 
-AC_DEFINE_UNQUOTED(CUPS_DOCROOT, "$docdir")
+done=no
+while test $done = no; do
+	case "$CUPS_DOCROOT" in
+	*'$'*) eval "CUPS_DOCROOT=$CUPS_DOCROOT";;
+	*) done=yes;;
+	esac
+done
+
+AC_DEFINE_UNQUOTED(CUPS_DOCROOT, "$CUPS_DOCROOT")
 AC_SUBST(CUPS_DOCROOT)
 
 # Fonts
@@ -221,8 +245,16 @@ else
 	CUPS_FONTPATH="$fontpath"
 fi
 
-AC_SUBST(CUPS_FONTPATH)
+done=no
+while test $done = no; do
+	case "$CUPS_FONTPATH" in
+	*'$'*) eval "CUPS_FONTPATH=$CUPS_FONTPATH";;
+	*) done=yes;;
+	esac
+done
+
 AC_DEFINE_UNQUOTED(CUPS_FONTPATH, "$CUPS_FONTPATH")
+AC_SUBST(CUPS_FONTPATH)
 
 # Locale data
 if test "$localedir" = "\${datarootdir}/locale"; then
@@ -240,6 +272,14 @@ else
 	CUPS_LOCALEDIR="$localedir"
 fi
 
+done=no
+while test $done = no; do
+	case "$CUPS_LOCALEDIR" in
+	*'$'*) eval "CUPS_LOCALEDIR=$CUPS_LOCALEDIR";;
+	*) done=yes;;
+	esac
+done
+
 AC_DEFINE_UNQUOTED(CUPS_LOCALEDIR, "$CUPS_LOCALEDIR")
 AC_SUBST(CUPS_LOCALEDIR)
 
@@ -248,7 +288,6 @@ AC_ARG_WITH(logdir, [  --with-logdir    
 
 if test x$logdir = x; then
 	CUPS_LOGDIR="$localstatedir/log/cups"
-	AC_DEFINE_UNQUOTED(CUPS_LOGDIR, "$localstatedir/log/cups")
 else
 	CUPS_LOGDIR="$logdir"
 fi
@@ -257,10 +296,13 @@ AC_SUBST(CUPS_LOGDIR)
 
 # Longer-term spool data
 CUPS_REQUESTS="$localstatedir/spool/cups"
-AC_DEFINE_UNQUOTED(CUPS_REQUESTS, "$localstatedir/spool/cups")
+AC_DEFINE_UNQUOTED(CUPS_REQUESTS, "$CUPS_REQUESTS")
 AC_SUBST(CUPS_REQUESTS)
 
 # Server executables...
+AC_ARG_WITH(serverbindir, [  --with-serverbindir     set path for server helper programs],serverbindir="$withval",serverbindir="")
+
+if test x$serverbindir = x; then
 case "$host_os_name" in
 	*bsd* | darwin*)
 		# *BSD and Darwin (macOS)
@@ -273,6 +315,10 @@ case "$host_os_name" in
 		CUPS_SERVERBIN="$exec_prefix/lib/cups"
 		;;
 esac
+else
+	INSTALL_SYSV=""
+	CUPS_SERVERBIN="$serverbindir"
+fi
 
 AC_DEFINE_UNQUOTED(CUPS_SERVERBIN, "$CUPS_SERVERBIN")
 AC_SUBST(CUPS_SERVERBIN)
@@ -280,7 +326,7 @@ AC_SUBST(INSTALL_SYSV)
 
 # Configuration files
 CUPS_SERVERROOT="$sysconfdir/cups"
-AC_DEFINE_UNQUOTED(CUPS_SERVERROOT, "$sysconfdir/cups")
+AC_DEFINE_UNQUOTED(CUPS_SERVERROOT, "$CUPS_SERVERROOT")
 AC_SUBST(CUPS_SERVERROOT)
 
 # Transient run-time state
