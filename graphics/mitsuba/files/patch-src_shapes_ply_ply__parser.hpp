--- src/shapes/ply/ply_parser.hpp.orig	2017-09-06 21:14:07 UTC
+++ src/shapes/ply/ply_parser.hpp
@@ -36,14 +36,9 @@
 #include <boost/tr1/memory.hpp>
 #include <boost/tr1/tuple.hpp>
 #else
-#if defined(_MSC_VER) && (_MSC_VER >= 1600)
 #include <functional>
 #include <memory>
 #include <tuple>
-#else
-#include <tr1/functional>
-#include <tr1/memory>
-#endif
 #endif
 
 #include <boost/mpl/fold.hpp>
@@ -63,32 +58,32 @@ class ply_parser
 {
 public:
 
-  typedef std::tr1::function<void (std::size_t, const std::string&)> info_callback_type;
-  typedef std::tr1::function<void (std::size_t, const std::string&)> warning_callback_type;
-  typedef std::tr1::function<void (std::size_t, const std::string&)> error_callback_type;
+  typedef std::function<void (std::size_t, const std::string&)> info_callback_type;
+  typedef std::function<void (std::size_t, const std::string&)> warning_callback_type;
+  typedef std::function<void (std::size_t, const std::string&)> error_callback_type;
 
-  typedef std::tr1::function<void ()> magic_callback_type;
-  typedef std::tr1::function<void (format_type, const std::string&)> format_callback_type;
-  typedef std::tr1::function<void (const std::string&)> comment_callback_type;
-  typedef std::tr1::function<void (const std::string&)> obj_info_callback_type;
-  typedef std::tr1::function<bool ()> end_header_callback_type;
+  typedef std::function<void ()> magic_callback_type;
+  typedef std::function<void (format_type, const std::string&)> format_callback_type;
+  typedef std::function<void (const std::string&)> comment_callback_type;
+  typedef std::function<void (const std::string&)> obj_info_callback_type;
+  typedef std::function<bool ()> end_header_callback_type;
 
-  typedef std::tr1::function<void()> begin_element_callback_type;
-  typedef std::tr1::function<void()> end_element_callback_type;
-  typedef std::tr1::tuple<begin_element_callback_type, end_element_callback_type> element_callbacks_type;
-  typedef std::tr1::function<element_callbacks_type (const std::string&, std::size_t)> element_definition_callback_type;
+  typedef std::function<void()> begin_element_callback_type;
+  typedef std::function<void()> end_element_callback_type;
+  typedef std::tuple<begin_element_callback_type, end_element_callback_type> element_callbacks_type;
+  typedef std::function<element_callbacks_type (const std::string&, std::size_t)> element_definition_callback_type;
 
   template <typename ScalarType>
   struct scalar_property_callback_type
   {
-    typedef std::tr1::function<void (ScalarType)> type;
+    typedef std::function<void (ScalarType)> type;
   };
 
   template <typename ScalarType>
   struct scalar_property_definition_callback_type
   {
     typedef typename scalar_property_callback_type<ScalarType>::type scalar_property_callback_type;
-    typedef std::tr1::function<scalar_property_callback_type (const std::string&, const std::string&)> type;
+    typedef std::function<scalar_property_callback_type (const std::string&, const std::string&)> type;
   };
 
   typedef boost::mpl::vector<int8, int16, int32, uint8, uint16, uint32, float32, float64> scalar_types;
@@ -138,19 +133,19 @@ public:
   template <typename SizeType, typename ScalarType>
   struct list_property_begin_callback_type
   {
-    typedef std::tr1::function<void (SizeType)> type;
+    typedef std::function<void (SizeType)> type;
   };
 
   template <typename SizeType, typename ScalarType>
   struct list_property_element_callback_type
   {
-    typedef std::tr1::function<void (ScalarType)> type;
+    typedef std::function<void (ScalarType)> type;
   };
 
   template <typename SizeType, typename ScalarType>
   struct list_property_end_callback_type
   {
-    typedef std::tr1::function<void ()> type;
+    typedef std::function<void ()> type;
   };
 
   template <typename SizeType, typename ScalarType>
@@ -159,8 +154,8 @@ public:
     typedef typename list_property_begin_callback_type<SizeType, ScalarType>::type list_property_begin_callback_type;
     typedef typename list_property_element_callback_type<SizeType, ScalarType>::type list_property_element_callback_type;
     typedef typename list_property_end_callback_type<SizeType, ScalarType>::type list_property_end_callback_type;
-    typedef std::tr1::function<
-      std::tr1::tuple<
+    typedef std::function<
+      std::tuple<
         list_property_begin_callback_type,
         list_property_element_callback_type,
         list_property_end_callback_type
@@ -288,7 +283,7 @@ private:
     std::size_t count;
     begin_element_callback_type begin_element_callback;
     end_element_callback_type end_element_callback;
-    std::vector<std::tr1::shared_ptr<property> > properties;
+    std::vector<std::shared_ptr<property> > properties;
   };
 
   flags_type flags_;
@@ -398,7 +393,7 @@ inline void ply::ply_parser::parse_scala
       warning_callback_(line_number_, "property '" + std::string(type_traits<scalar_type>::name()) + " " + property_name + "' of element '" + current_element_->name + "' is not handled");
     }
   }
-  current_element_->properties.push_back(std::tr1::shared_ptr<property>(new scalar_property<scalar_type>(property_name, scalar_property_callback)));
+  current_element_->properties.push_back(std::shared_ptr<property>(new scalar_property<scalar_type>(property_name, scalar_property_callback)));
 }
 
 template <typename SizeType, typename ScalarType>
@@ -414,16 +409,16 @@ inline void ply::ply_parser::parse_list_
   typedef typename list_property_begin_callback_type<size_type, scalar_type>::type list_property_begin_callback_type;
   typedef typename list_property_element_callback_type<size_type, scalar_type>::type list_property_element_callback_type;
   typedef typename list_property_end_callback_type<size_type, scalar_type>::type list_property_end_callback_type;
-  std::tr1::tuple<list_property_begin_callback_type, list_property_element_callback_type, list_property_end_callback_type> list_property_callbacks;
+  std::tuple<list_property_begin_callback_type, list_property_element_callback_type, list_property_end_callback_type> list_property_callbacks;
   if (list_property_definition_callback) {
     list_property_callbacks = list_property_definition_callback(current_element_->name, property_name);
   }
-  if (!std::tr1::get<0>(list_property_callbacks) || !std::tr1::get<1>(list_property_callbacks) || !std::tr1::get<2>(list_property_callbacks)) {
+  if (!std::get<0>(list_property_callbacks) || !std::get<1>(list_property_callbacks) || !std::get<2>(list_property_callbacks)) {
     if (warning_callback_) {
       warning_callback_(line_number_, "property 'list " + std::string(type_traits<size_type>::name()) + " " + std::string(type_traits<scalar_type>::name()) + " " + property_name + "' of element '" + current_element_->name + "' is not handled");
     }
   }
-  current_element_->properties.push_back(std::tr1::shared_ptr<property>(new list_property<size_type, scalar_type>(property_name, std::tr1::get<0>(list_property_callbacks), std::tr1::get<1>(list_property_callbacks), std::tr1::get<2>(list_property_callbacks))));
+  current_element_->properties.push_back(std::shared_ptr<property>(new list_property<size_type, scalar_type>(property_name, std::get<0>(list_property_callbacks), std::get<1>(list_property_callbacks), std::get<2>(list_property_callbacks))));
 }
 
 template <typename ScalarType>
