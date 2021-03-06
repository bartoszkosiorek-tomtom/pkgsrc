$NetBSD: patch-prediction_user__history__predictor.h,v 1.1 2020/06/19 05:45:30 taca Exp $

Fix from https://github.com/google/mozc/issues/460

--- prediction/user_history_predictor.h.orig	2017-11-02 13:32:47.000000000 +0000
+++ prediction/user_history_predictor.h
@@ -61,11 +61,15 @@ class Segments;
 class UserHistoryPredictorSyncer;
 
 // Added serialization method for UserHistory.
-class UserHistoryStorage : public mozc::user_history_predictor::UserHistory {
+class UserHistoryStorage {
  public:
   explicit UserHistoryStorage(const string &filename);
   ~UserHistoryStorage();
 
+  // Instance of base class generated by Protocol Buffers compiler.
+  // Regular inheritance strongly discouraged.
+  mozc::user_history_predictor::UserHistory user_history_base;
+
   // Loads from encrypted file.
   bool Load();
 
