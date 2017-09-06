--- src/shapes/ply/ply_parser.cpp.orig	2017-09-06 21:14:02 UTC
+++ src/shapes/ply/ply_parser.cpp
@@ -9,7 +9,7 @@ bool ply::ply_parser::parse(std::istream
   std::size_t number_of_format_statements = 0, number_of_element_statements = 0, number_of_property_statements = 0, number_of_obj_info_statements = 0, number_of_comment_statements = 0;
 
   format_type format = ascii_format;
-  std::vector< std::tr1::shared_ptr<element> > elements;
+  std::vector< std::shared_ptr<element> > elements;
 
   // magic
   char magic[3];
@@ -103,7 +103,7 @@ bool ply::ply_parser::parse(std::istream
           }
           return false;
         }
-        std::vector< std::tr1::shared_ptr<element> >::const_iterator iterator;
+        std::vector< std::shared_ptr<element> >::const_iterator iterator;
         for (iterator = elements.begin(); iterator != elements.end(); ++iterator) {
           const struct element& element = *(iterator->get());
           if (element.name == name) {
@@ -121,8 +121,8 @@ bool ply::ply_parser::parse(std::istream
         if (element_definition_callbacks_) {
           element_callbacks = element_definition_callbacks_(name, count);
         }
-        std::tr1::shared_ptr<element> element_ptr(new element(name, count, std::tr1::get<0>(element_callbacks), std::tr1::get<1>(element_callbacks)));
-        elements.push_back(std::tr1::shared_ptr<element>(element_ptr));
+        std::shared_ptr<element> element_ptr(new element(name, count, std::get<0>(element_callbacks), std::get<1>(element_callbacks)));
+        elements.push_back(std::shared_ptr<element>(element_ptr));
         current_element_ = element_ptr.get();
       }
 
@@ -154,7 +154,7 @@ bool ply::ply_parser::parse(std::istream
             }
             return false;
           }
-          std::vector< std::tr1::shared_ptr<property> >::const_iterator iterator;
+          std::vector< std::shared_ptr<property> >::const_iterator iterator;
           for (iterator = current_element_->properties.begin(); iterator != current_element_->properties.end(); ++iterator) {
             const struct property& property = *(iterator->get());
             if (property.name == name) {
@@ -216,7 +216,7 @@ bool ply::ply_parser::parse(std::istream
             }
             return false;
           }
-          std::vector< std::tr1::shared_ptr<property> >::const_iterator iterator;
+          std::vector< std::shared_ptr<property> >::const_iterator iterator;
           for (iterator = current_element_->properties.begin(); iterator != current_element_->properties.end(); ++iterator) {
             const struct property& property = *(iterator->get());
             if (property.name == name) {
@@ -392,7 +392,7 @@ bool ply::ply_parser::parse(std::istream
 
   // ascii
   if (format == ascii_format) {
-    for (std::vector< std::tr1::shared_ptr<element> >::const_iterator element_iterator = elements.begin(); element_iterator != elements.end(); ++element_iterator) {
+    for (std::vector< std::shared_ptr<element> >::const_iterator element_iterator = elements.begin(); element_iterator != elements.end(); ++element_iterator) {
       struct element& element = *(element_iterator->get());
       for (std::size_t element_index = 0; element_index < element.count; ++element_index) {
         if (element.begin_element_callback) {
@@ -408,7 +408,7 @@ bool ply::ply_parser::parse(std::istream
         std::istringstream stringstream(line);
         stringstream.unsetf(std::ios_base::skipws);
         stringstream >> std::ws;
-        for (std::vector< std::tr1::shared_ptr<property> >::const_iterator property_iterator = element.properties.begin(); property_iterator != element.properties.end(); ++property_iterator) {
+        for (std::vector< std::shared_ptr<property> >::const_iterator property_iterator = element.properties.begin(); property_iterator != element.properties.end(); ++property_iterator) {
           struct property& property = *(property_iterator->get());
           if (property.parse(*this, format, stringstream) == false) {
             return false;
@@ -437,13 +437,13 @@ bool ply::ply_parser::parse(std::istream
 
   // binary
   else {
-    for (std::vector< std::tr1::shared_ptr<element> >::const_iterator element_iterator = elements.begin(); element_iterator != elements.end(); ++element_iterator) {
+    for (std::vector< std::shared_ptr<element> >::const_iterator element_iterator = elements.begin(); element_iterator != elements.end(); ++element_iterator) {
       struct element& element = *(element_iterator->get());
       for (std::size_t element_index = 0; element_index < element.count; ++element_index) {
         if (element.begin_element_callback) {
           element.begin_element_callback();
         }
-        for (std::vector< std::tr1::shared_ptr<property> >::const_iterator property_iterator = element.properties.begin(); property_iterator != element.properties.end(); ++property_iterator) {
+        for (std::vector< std::shared_ptr<property> >::const_iterator property_iterator = element.properties.begin(); property_iterator != element.properties.end(); ++property_iterator) {
           struct property& property = *(property_iterator->get());
           if (property.parse(*this, format, istream) == false) {
             return false;
