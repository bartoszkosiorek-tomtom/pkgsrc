$NetBSD: patch-src_Utils.cpp,v 1.4 2020/05/25 20:26:51 adam Exp $

Fix building on NetBSD.
d_type is not POSIX, provide workaround for SunOS.

--- src/Utils.cpp.orig	2020-03-27 16:51:24.000000000 +0000
+++ src/Utils.cpp
@@ -25,10 +25,13 @@ extern "C" {
 #include "third-party/fast-sha1/sha1-fast.c"
 }
 
-#if defined(__OpenBSD__) || defined(__APPLE__)
+#if defined(__NetBSD__) || defined(__OpenBSD__) || defined(__APPLE__)
 #include <net/if_dl.h>
 #include <ifaddrs.h>
 #endif
+#ifdef __sun
+struct stat s;
+#endif
 
 static map<string, int> initTcpStatesStr2State() {
   map<string, int>states_map;
@@ -2167,7 +2170,12 @@ static bool scan_dir(const char * dir_na
     if(!entry) break;
     d_name = entry->d_name;
 
+#ifdef __sun
+    stat(entry->d_name, &s);
+    if (s.st_mode & S_IFREG) {
+#else
     if(entry->d_type & DT_REG) {
+#endif
       snprintf(path, sizeof(path), "%s/%s", dir_name, entry->d_name);
       if(!stat(path, &buf)) {
         struct dirent *temp = (struct dirent *)malloc(sizeof(struct dirent));
@@ -2177,7 +2185,11 @@ static bool scan_dir(const char * dir_na
 	  *total += buf.st_size;
       }
 
+#ifdef __sun
+    } else if (s.st_mode & S_IFDIR) {
+#else
     } else if(entry->d_type & DT_DIR) {
+#endif
       if(strncmp (d_name, "..", 2) != 0 &&
 	 strncmp (d_name, ".", 1) != 0) {
         path_length = snprintf (path, MAX_PATH,
