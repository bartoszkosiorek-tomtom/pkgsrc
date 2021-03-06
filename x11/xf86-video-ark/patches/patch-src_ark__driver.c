$NetBSD: patch-src_ark__driver.c,v 1.1 2015/04/02 22:16:46 tnn Exp $

From 3a3eb72baec46f48e6cf15a834271c3d3386deac Mon Sep 17 00:00:00 2001
From: Gaetan Nadon <memsize@videotron.ca>
Date: Tue, 17 Sep 2013 15:55:37 -0400
Subject: Remove usage of mibstore.h (removed from server)

The module had a compile error for this missing header file.

Changes similar to vmware commit
23d87c92b7211cc5249eefe4ab3a2c7f370e279e

Reviewed-by: Alex Deucher <alexander.deucher@amd.com>
Signed-off-by: Gaetan Nadon <memsize@videotron.ca>

diff --git a/src/ark_driver.c b/src/ark_driver.c
index b7c287c..65cfe84 100644
--- src/ark_driver.c
+++ src/ark_driver.c
@@ -39,7 +39,6 @@
 #include "compiler.h"
 #include "mipointer.h"
 #include "micmap.h"
-#include "mibstore.h"
 #include "fb.h"
 #include "ark.h"
 
@@ -538,7 +537,6 @@ static Bool ARKScreenInit(SCREEN_INIT_ARGS_DECL)
 
 	fbPictureInit (pScreen, 0, 0);
 
-	miInitializeBackingStore(pScreen);
 	xf86SetBackingStore(pScreen);
 
 	if (!pARK->NoAccel) {
