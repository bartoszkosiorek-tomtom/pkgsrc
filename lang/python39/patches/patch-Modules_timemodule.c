$NetBSD: patch-Modules_timemodule.c,v 1.1 2020/11/12 10:58:21 sjmulder Exp $

Support for macOS 11 and Apple Silicon (ARM). Backported from:
https://github.com/python/cpython/pull/22855

--- Modules/timemodule.c.orig	2020-10-05 15:07:58.000000000 +0000
+++ Modules/timemodule.c
@@ -51,6 +51,15 @@
 #define _Py_tzname tzname
 #endif
 
+#if defined(__APPLE__ ) && defined(__has_builtin) 
+#  if __has_builtin(__builtin_available)
+#    define HAVE_CLOCK_GETTIME_RUNTIME __builtin_available(macOS 10.12, iOS 10.0, tvOS 10.0, watchOS 3.0, *)
+#  endif
+#endif
+#ifndef HAVE_CLOCK_GETTIME_RUNTIME
+#  define HAVE_CLOCK_GETTIME_RUNTIME 1
+#endif
+
 #define SEC_TO_NS (1000 * 1000 * 1000)
 
 /* Forward declarations */
@@ -149,6 +158,16 @@ perf_counter(_Py_clock_info_t *info)
 }
 
 #ifdef HAVE_CLOCK_GETTIME
+
+#ifdef __APPLE__
+/* 
+ * The clock_* functions will be removed from the module
+ * dict entirely when the C API is not available.
+ */
+#pragma clang diagnostic push
+#pragma clang diagnostic ignored "-Wunguarded-availability"
+#endif
+
 static PyObject *
 time_clock_gettime(PyObject *self, PyObject *args)
 {
@@ -297,6 +316,11 @@ PyDoc_STRVAR(clock_getres_doc,
 "clock_getres(clk_id) -> floating point number\n\
 \n\
 Return the resolution (precision) of the specified clock clk_id.");
+
+#ifdef __APPLE__
+#pragma clang diagnostic pop
+#endif
+
 #endif   /* HAVE_CLOCK_GETRES */
 
 #ifdef HAVE_PTHREAD_GETCPUCLOCKID
@@ -1162,31 +1186,35 @@ _PyTime_GetProcessTimeWithInfo(_PyTime_t
 #if defined(HAVE_CLOCK_GETTIME) \
     && (defined(CLOCK_PROCESS_CPUTIME_ID) || defined(CLOCK_PROF))
     struct timespec ts;
+
+    if (HAVE_CLOCK_GETTIME_RUNTIME) {
+
 #ifdef CLOCK_PROF
-    const clockid_t clk_id = CLOCK_PROF;
-    const char *function = "clock_gettime(CLOCK_PROF)";
+        const clockid_t clk_id = CLOCK_PROF;
+        const char *function = "clock_gettime(CLOCK_PROF)";
 #else
-    const clockid_t clk_id = CLOCK_PROCESS_CPUTIME_ID;
-    const char *function = "clock_gettime(CLOCK_PROCESS_CPUTIME_ID)";
+        const clockid_t clk_id = CLOCK_PROCESS_CPUTIME_ID;
+        const char *function = "clock_gettime(CLOCK_PROCESS_CPUTIME_ID)";
 #endif
 
-    if (clock_gettime(clk_id, &ts) == 0) {
-        if (info) {
-            struct timespec res;
-            info->implementation = function;
-            info->monotonic = 1;
-            info->adjustable = 0;
-            if (clock_getres(clk_id, &res)) {
-                PyErr_SetFromErrno(PyExc_OSError);
-                return -1;
+        if (clock_gettime(clk_id, &ts) == 0) {
+            if (info) {
+                struct timespec res;
+                info->implementation = function;
+                info->monotonic = 1;
+                info->adjustable = 0;
+                if (clock_getres(clk_id, &res)) {
+                    PyErr_SetFromErrno(PyExc_OSError);
+                    return -1;
+                }
+                info->resolution = res.tv_sec + res.tv_nsec * 1e-9;
             }
-            info->resolution = res.tv_sec + res.tv_nsec * 1e-9;
-        }
 
-        if (_PyTime_FromTimespec(tp, &ts) < 0) {
-            return -1;
+            if (_PyTime_FromTimespec(tp, &ts) < 0) {
+                return -1;
+            }
+            return 0;
         }
-        return 0;
     }
 #endif
 
@@ -1373,6 +1401,16 @@ _PyTime_GetThreadTimeWithInfo(_PyTime_t 
 
 #elif defined(HAVE_CLOCK_GETTIME) && defined(CLOCK_PROCESS_CPUTIME_ID)
 #define HAVE_THREAD_TIME
+
+#if defined(__APPLE__) && defined(__has_attribute) && __has_attribute(availability)
+static int
+_PyTime_GetThreadTimeWithInfo(_PyTime_t *tp, _Py_clock_info_t *info) 
+     __attribute__((availability(macos, introduced=10.12)))
+     __attribute__((availability(ios, introduced=10.0)))
+     __attribute__((availability(tvos, introduced=10.0)))
+     __attribute__((availability(watchos, introduced=3.0)));
+#endif
+
 static int
 _PyTime_GetThreadTimeWithInfo(_PyTime_t *tp, _Py_clock_info_t *info)
 {
@@ -1404,6 +1442,15 @@ _PyTime_GetThreadTimeWithInfo(_PyTime_t 
 #endif
 
 #ifdef HAVE_THREAD_TIME
+#ifdef __APPLE__
+/* 
+ * The clock_* functions will be removed from the module
+ * dict entirely when the C API is not available.
+ */
+#pragma clang diagnostic push
+#pragma clang diagnostic ignored "-Wunguarded-availability"
+#endif
+
 static PyObject *
 time_thread_time(PyObject *self, PyObject *unused)
 {
@@ -1434,6 +1481,11 @@ PyDoc_STRVAR(thread_time_ns_doc,
 \n\
 Thread time for profiling as nanoseconds:\n\
 sum of the kernel and user-space CPU time.");
+
+#ifdef __APPLE__
+#pragma clang diagnostic pop
+#endif
+
 #endif
 
 
@@ -1483,9 +1535,19 @@ time_get_clock_info(PyObject *self, PyOb
     }
 #ifdef HAVE_THREAD_TIME
     else if (strcmp(name, "thread_time") == 0) {
-        if (_PyTime_GetThreadTimeWithInfo(&t, &info) < 0) {
+
+#ifdef __APPLE__
+        if (HAVE_CLOCK_GETTIME_RUNTIME) {
+#endif
+            if (_PyTime_GetThreadTimeWithInfo(&t, &info) < 0) {
+                return NULL;
+            }
+#ifdef __APPLE__
+        } else {
+            PyErr_SetString(PyExc_ValueError, "unknown clock");
             return NULL;
         }
+#endif
     }
 #endif
     else {
@@ -1766,68 +1828,116 @@ if it is -1, mktime() should guess based
 static int
 time_exec(PyObject *module)
 {
+#if defined(__APPLE__) && defined(HAVE_CLOCK_GETTIME)
+    if (HAVE_CLOCK_GETTIME_RUNTIME) {
+        /* pass: ^^^ cannot use '!' here */
+    } else {
+        PyObject* dct = PyModule_GetDict(module);
+        if (dct == NULL) {
+            return -1;
+        }
+
+        if (PyDict_DelItemString(dct, "clock_gettime") == -1) {
+            PyErr_Clear();
+        }
+        if (PyDict_DelItemString(dct, "clock_gettime_ns") == -1) {
+            PyErr_Clear();
+        }
+        if (PyDict_DelItemString(dct, "clock_settime") == -1) {
+            PyErr_Clear();
+        }
+        if (PyDict_DelItemString(dct, "clock_settime_ns") == -1) {
+            PyErr_Clear();
+        }
+        if (PyDict_DelItemString(dct, "clock_getres") == -1) {
+            PyErr_Clear();
+        }
+    }
+#endif
+#if defined(__APPLE__) && defined(HAVE_THREAD_TIME)
+    if (HAVE_CLOCK_GETTIME_RUNTIME) {
+        /* pass: ^^^ cannot use '!' here */
+    } else {
+        PyObject* dct = PyModule_GetDict(module);
+
+        if (PyDict_DelItemString(dct, "thread_time") == -1) {
+            PyErr_Clear();
+        }
+        if (PyDict_DelItemString(dct, "thread_time_ns") == -1) {
+            PyErr_Clear();
+        }
+    }
+#endif
     /* Set, or reset, module variables like time.timezone */
     if (init_timezone(module) < 0) {
         return -1;
     }
 
 #if defined(HAVE_CLOCK_GETTIME) || defined(HAVE_CLOCK_SETTIME) || defined(HAVE_CLOCK_GETRES)
+    if (HAVE_CLOCK_GETTIME_RUNTIME) {
 
 #ifdef CLOCK_REALTIME
-    if (PyModule_AddIntMacro(module, CLOCK_REALTIME) < 0) {
-        return -1;
-    }
+        if (PyModule_AddIntMacro(module, CLOCK_REALTIME) < 0) {
+            return -1;
+        }
 #endif
+
 #ifdef CLOCK_MONOTONIC
-    if (PyModule_AddIntMacro(module, CLOCK_MONOTONIC) < 0) {
-        return -1;
-    }
+
+        if (PyModule_AddIntMacro(module, CLOCK_MONOTONIC) < 0) {
+            return -1;
+        }
+
 #endif
 #ifdef CLOCK_MONOTONIC_RAW
-    if (PyModule_AddIntMacro(module, CLOCK_MONOTONIC_RAW) < 0) {
-        return -1;
-    }
+        if (PyModule_AddIntMacro(module, CLOCK_MONOTONIC_RAW) < 0) {
+            return -1;
+        }
 #endif
+
 #ifdef CLOCK_HIGHRES
-    if (PyModule_AddIntMacro(module, CLOCK_HIGHRES) < 0) {
-        return -1;
-    }
+        if (PyModule_AddIntMacro(module, CLOCK_HIGHRES) < 0) {
+            return -1;
+        }
 #endif
 #ifdef CLOCK_PROCESS_CPUTIME_ID
-    if (PyModule_AddIntMacro(module, CLOCK_PROCESS_CPUTIME_ID) < 0) {
-        return -1;
-    }
+        if (PyModule_AddIntMacro(module, CLOCK_PROCESS_CPUTIME_ID) < 0) {
+            return -1;
+        }
 #endif
+
 #ifdef CLOCK_THREAD_CPUTIME_ID
-    if (PyModule_AddIntMacro(module, CLOCK_THREAD_CPUTIME_ID) < 0) {
-        return -1;
-    }
+        if (PyModule_AddIntMacro(module, CLOCK_THREAD_CPUTIME_ID) < 0) {
+            return -1;
+        }
 #endif
 #ifdef CLOCK_PROF
-    if (PyModule_AddIntMacro(module, CLOCK_PROF) < 0) {
-        return -1;
-    }
+        if (PyModule_AddIntMacro(module, CLOCK_PROF) < 0) {
+            return -1;
+        }
 #endif
 #ifdef CLOCK_BOOTTIME
-    if (PyModule_AddIntMacro(module, CLOCK_BOOTTIME) < 0) {
-        return -1;
-    }
+        if (PyModule_AddIntMacro(module, CLOCK_BOOTTIME) < 0) {
+            return -1;
+        }
 #endif
 #ifdef CLOCK_TAI
-    if (PyModule_AddIntMacro(module, CLOCK_TAI) < 0) {
-        return -1;
-    }
+        if (PyModule_AddIntMacro(module, CLOCK_TAI) < 0) {
+            return -1;
+        }
 #endif
 #ifdef CLOCK_UPTIME
-    if (PyModule_AddIntMacro(module, CLOCK_UPTIME) < 0) {
-        return -1;
-    }
+        if (PyModule_AddIntMacro(module, CLOCK_UPTIME) < 0) {
+            return -1;
+        }
 #endif
 #ifdef CLOCK_UPTIME_RAW
-    if (PyModule_AddIntMacro(module, CLOCK_UPTIME_RAW) < 0) {
-        return -1;
-    }
+
+        if (PyModule_AddIntMacro(module, CLOCK_UPTIME_RAW) < 0) {
+            return -1;
+        }
 #endif
+    }
 
 #endif  /* defined(HAVE_CLOCK_GETTIME) || defined(HAVE_CLOCK_SETTIME) || defined(HAVE_CLOCK_GETRES) */
 
