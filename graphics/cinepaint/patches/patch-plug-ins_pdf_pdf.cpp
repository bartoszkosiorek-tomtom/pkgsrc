$NetBSD: patch-plug-ins_pdf_pdf.cpp,v 1.2 2018/12/31 13:11:12 ryoon Exp $

--- plug-ins/pdf/pdf.cpp.orig	2008-10-10 05:44:15.000000000 +0000
+++ plug-ins/pdf/pdf.cpp
@@ -47,10 +47,10 @@ extern "C" {
 #include "lib/wire/libtile.h"
 #include "plugin_pdb.h"
 #include "libgimp/stdplugins-intl.h"
+}
 #ifdef HAVE_OY
-#include <oyranos/oyranos.h>
+#include <oyranos.h>
 #endif
-}
 
 #define WARN_S(text) cout <<__FILE__<<":"<<__LINE__<<" "<< text << endl;
 
@@ -377,8 +377,6 @@ load_image(const char* filename)
     // set a default profile for cmyk
 #ifdef OYRANOS_H
 # if OYRANOS_API > 12
-    using namespace oyranos;
-
     if( vals.colourspace == PDF_CMYK )
       profile_name = oyGetDefaultProfileName (oyEDITING_CMYK, myAllocFunc);
     else
