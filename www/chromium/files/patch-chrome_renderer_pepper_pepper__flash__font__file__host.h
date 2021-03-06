--- chrome/renderer/pepper/pepper_flash_font_file_host.h.orig	2018-12-13 18:23:18.267950000 +0100
+++ chrome/renderer/pepper/pepper_flash_font_file_host.h	2018-12-13 18:24:04.656797000 +0100
@@ -14,7 +14,7 @@
 #include "ppapi/c/private/pp_private_font_charset.h"
 #include "ppapi/host/resource_host.h"
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/files/file.h"
 #elif defined(OS_WIN)
 #include "third_party/skia/include/core/SkRefCnt.h"
@@ -50,7 +50,7 @@
                          uint32_t table);
   bool GetFontData(uint32_t table, void* buffer, size_t* length);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   base::File font_file_;
 #elif defined(OS_WIN)
   sk_sp<SkTypeface> typeface_;
