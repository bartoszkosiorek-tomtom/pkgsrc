$NetBSD: patch-dictionary_user__dictionary__storage.cc,v 1.1 2020/06/19 05:45:30 taca Exp $

Fix from https://github.com/google/mozc/issues/460

--- dictionary/user_dictionary_storage.cc.orig	2017-11-02 13:32:47.000000000 +0000
+++ dictionary/user_dictionary_storage.cc
@@ -114,7 +114,7 @@ bool UserDictionaryStorage::LoadInternal
   mozc::protobuf::io::IstreamInputStream zero_copy_input(&ifs);
   mozc::protobuf::io::CodedInputStream decoder(&zero_copy_input);
   decoder.SetTotalBytesLimit(kDefaultTotalBytesLimit, -1);
-  if (!ParseFromCodedStream(&decoder)) {
+  if (!user_dictionary_storage_base.ParseFromCodedStream(&decoder)) {
     LOG(ERROR) << "Failed to parse";
     if (!decoder.ConsumedEntireMessage() || !ifs.eof()) {
       LOG(ERROR) << "ParseFromStream failed: file seems broken";
@@ -142,11 +142,11 @@ bool UserDictionaryStorage::Load() {
   }
 
   // Check dictionary id here. if id is 0, assign random ID.
-  for (int i = 0; i < dictionaries_size(); ++i) {
-    const UserDictionary &dict = dictionaries(i);
+  for (int i = 0; i < user_dictionary_storage_base.dictionaries_size(); ++i) {
+    const UserDictionary &dict = user_dictionary_storage_base.dictionaries(i);
     if (dict.id() == 0) {
-      mutable_dictionaries(i)->set_id(
-          UserDictionaryUtil::CreateNewDictionaryId(*this));
+      user_dictionary_storage_base.mutable_dictionaries(i)->set_id(
+          UserDictionaryUtil::CreateNewDictionaryId(this->user_dictionary_storage_base));
     }
   }
 
@@ -176,7 +176,7 @@ bool UserDictionaryStorage::Save() {
       return false;
     }
 
-    if (!SerializeToOstream(&ofs)) {
+    if (!user_dictionary_storage_base.SerializeToOstream(&ofs)) {
       LOG(ERROR) << "SerializeToString failed";
       last_error_type_ = SYNC_FAILURE;
       return false;
@@ -232,7 +232,7 @@ bool UserDictionaryStorage::ExportDictio
     return false;
   }
 
-  const UserDictionary &dic = dictionaries(index);
+  const UserDictionary &dic = user_dictionary_storage_base.dictionaries(index);
   for (size_t i = 0; i < dic.entries_size(); ++i) {
     const UserDictionaryEntry &entry = dic.entries(i);
     ofs << entry.key() << "\t" << entry.value() << "\t"
@@ -246,7 +246,7 @@ bool UserDictionaryStorage::ExportDictio
 bool UserDictionaryStorage::CreateDictionary(
     const string &dic_name, uint64 *new_dic_id) {
   UserDictionaryCommandStatus::Status status =
-      UserDictionaryUtil::CreateDictionary(this, dic_name, new_dic_id);
+      UserDictionaryUtil::CreateDictionary(&this->user_dictionary_storage_base, dic_name, new_dic_id);
   // Update last_error_type_
   switch (status) {
     case UserDictionaryCommandStatus::DICTIONARY_NAME_EMPTY:
@@ -278,7 +278,7 @@ bool UserDictionaryStorage::CreateDictio
 }
 
 bool UserDictionaryStorage::DeleteDictionary(uint64 dic_id) {
-  if (!UserDictionaryUtil::DeleteDictionary(this, dic_id, NULL, NULL)) {
+  if (!UserDictionaryUtil::DeleteDictionary(&this->user_dictionary_storage_base, dic_id, NULL, NULL)) {
     // Failed to delete dictionary.
     last_error_type_ = INVALID_DICTIONARY_ID;
     return false;
@@ -309,8 +309,8 @@ bool UserDictionaryStorage::RenameDictio
     return true;
   }
 
-  for (int i = 0; i < dictionaries_size(); ++i) {
-    if (dic_name == dictionaries(i).name()) {
+  for (int i = 0; i < user_dictionary_storage_base.dictionaries_size(); ++i) {
+    if (dic_name == user_dictionary_storage_base.dictionaries(i).name()) {
       last_error_type_ = DUPLICATED_DICTIONARY_NAME;
       LOG(ERROR) << "duplicated dictionary name";
       return false;
@@ -323,14 +323,14 @@ bool UserDictionaryStorage::RenameDictio
 }
 
 int UserDictionaryStorage::GetUserDictionaryIndex(uint64 dic_id) const {
-  return UserDictionaryUtil::GetUserDictionaryIndexById(*this, dic_id);
+  return UserDictionaryUtil::GetUserDictionaryIndexById(this->user_dictionary_storage_base, dic_id);
 }
 
 bool UserDictionaryStorage::GetUserDictionaryId(const string &dic_name,
                                                 uint64 *dic_id) {
-  for (size_t i = 0; i < dictionaries_size(); ++i) {
-    if (dic_name == dictionaries(i).name()) {
-      *dic_id = dictionaries(i).id();
+  for (size_t i = 0; i < user_dictionary_storage_base.dictionaries_size(); ++i) {
+    if (dic_name == user_dictionary_storage_base.dictionaries(i).name()) {
+      *dic_id = user_dictionary_storage_base.dictionaries(i).id();
       return true;
     }
   }
@@ -340,7 +340,7 @@ bool UserDictionaryStorage::GetUserDicti
 
 user_dictionary::UserDictionary *UserDictionaryStorage::GetUserDictionary(
     uint64 dic_id) {
-  return UserDictionaryUtil::GetMutableUserDictionaryById(this, dic_id);
+  return UserDictionaryUtil::GetMutableUserDictionaryById(&this->user_dictionary_storage_base, dic_id);
 }
 
 UserDictionaryStorage::UserDictionaryStorageErrorType
@@ -357,8 +357,8 @@ bool UserDictionaryStorage::AddToAutoReg
   }
 
   int auto_index = -1;
-  for (int i = 0; i < dictionaries_size(); ++i) {
-    if (dictionaries(i).name() == kAutoRegisteredDictionaryName) {
+  for (int i = 0; i < user_dictionary_storage_base.dictionaries_size(); ++i) {
+    if (user_dictionary_storage_base.dictionaries(i).name() == kAutoRegisteredDictionaryName) {
       auto_index = i;
       break;
     }
@@ -366,17 +366,17 @@ bool UserDictionaryStorage::AddToAutoReg
 
   UserDictionary *dic = NULL;
   if (auto_index == -1) {
-    if (UserDictionaryUtil::IsStorageFull(*this)) {
+    if (UserDictionaryUtil::IsStorageFull(this->user_dictionary_storage_base)) {
       last_error_type_ = TOO_MANY_DICTIONARIES;
       LOG(ERROR) << "too many dictionaries";
       UnLock();
       return false;
     }
-    dic = add_dictionaries();
-    dic->set_id(UserDictionaryUtil::CreateNewDictionaryId(*this));
+    dic = user_dictionary_storage_base.add_dictionaries();
+    dic->set_id(UserDictionaryUtil::CreateNewDictionaryId(this->user_dictionary_storage_base));
     dic->set_name(kAutoRegisteredDictionaryName);
   } else {
-    dic = mutable_dictionaries(auto_index);
+    dic = user_dictionary_storage_base.mutable_dictionaries(auto_index);
   }
 
   if (dic == NULL) {
@@ -415,13 +415,13 @@ bool UserDictionaryStorage::AddToAutoReg
 }
 
 bool UserDictionaryStorage::ConvertSyncDictionariesToNormalDictionaries() {
-  if (CountSyncableDictionaries(*this) == 0) {
+  if (CountSyncableDictionaries(this->user_dictionary_storage_base) == 0) {
     return false;
   }
 
-  for (int dictionary_index = dictionaries_size() - 1;
+  for (int dictionary_index = user_dictionary_storage_base.dictionaries_size() - 1;
        dictionary_index >= 0; --dictionary_index) {
-    UserDictionary *dic = mutable_dictionaries(dictionary_index);
+    UserDictionary *dic = user_dictionary_storage_base.mutable_dictionaries(dictionary_index);
     if (!dic->syncable()) {
       continue;
     }
@@ -438,10 +438,10 @@ bool UserDictionaryStorage::ConvertSyncD
 
     // Delete removed or unused sync dictionaries.
     if (dic->removed() || dic->entries_size() == 0) {
-      for (int i = dictionary_index + 1; i < dictionaries_size(); ++i) {
-        mutable_dictionaries()->SwapElements(i - 1, i);
+      for (int i = dictionary_index + 1; i < user_dictionary_storage_base.dictionaries_size(); ++i) {
+        user_dictionary_storage_base.mutable_dictionaries()->SwapElements(i - 1, i);
       }
-      mutable_dictionaries()->RemoveLast();
+      user_dictionary_storage_base.mutable_dictionaries()->RemoveLast();
       continue;
     }
 
@@ -450,7 +450,7 @@ bool UserDictionaryStorage::ConvertSyncD
           kDictionaryNameConvertedFromSyncableDictionary;
       int index = 0;
       while (UserDictionaryUtil::ValidateDictionaryName(
-                 *this, new_dictionary_name)
+                 this->user_dictionary_storage_base, new_dictionary_name)
              != UserDictionaryCommandStatus::USER_DICTIONARY_COMMAND_SUCCESS) {
         ++index;
         new_dictionary_name = Util::StringPrintf(
@@ -461,7 +461,7 @@ bool UserDictionaryStorage::ConvertSyncD
     dic->set_syncable(false);
   }
 
-  DCHECK_EQ(0, CountSyncableDictionaries(*this));
+  DCHECK_EQ(0, CountSyncableDictionaries(this->user_dictionary_storage_base));
 
   return true;
 }
@@ -492,7 +492,7 @@ size_t UserDictionaryStorage::max_dictio
 bool UserDictionaryStorage::IsValidDictionaryName(const string &name) {
   UserDictionaryCommandStatus::Status status =
       UserDictionaryUtil::ValidateDictionaryName(
-          UserDictionaryStorage::default_instance(), name);
+          user_dictionary::UserDictionaryStorage::default_instance(), name);
 
   // Update last_error_type_.
   switch (status) {
