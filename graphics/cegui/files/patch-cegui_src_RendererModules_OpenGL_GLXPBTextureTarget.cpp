--- cegui/src/RendererModules/OpenGL/GLXPBTextureTarget.cpp.orig	2017-09-04 09:23:19.204908000 +0100
+++ cegui/src/RendererModules/OpenGL/GLXPBTextureTarget.cpp	2017-09-04 09:23:27.141062000 +0100
@@ -157,8 +157,8 @@
 {
     int creation_attrs[] =
     {
-        GLX_PBUFFER_WIDTH, d_area.getWidth(),
-        GLX_PBUFFER_HEIGHT, d_area.getHeight(),
+        GLX_PBUFFER_WIDTH, static_cast<int>(d_area.getWidth()),
+        GLX_PBUFFER_HEIGHT, static_cast<int>(d_area.getHeight()),
         GLX_LARGEST_PBUFFER, True,
         GLX_PRESERVED_CONTENTS, True,
         None
