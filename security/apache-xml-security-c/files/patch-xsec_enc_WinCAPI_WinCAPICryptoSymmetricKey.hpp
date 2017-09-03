--- xsec/enc/WinCAPI/WinCAPICryptoSymmetricKey.hpp.orig	2017-09-03 18:59:55 UTC
+++ xsec/enc/WinCAPI/WinCAPICryptoSymmetricKey.hpp
@@ -158,7 +158,7 @@ public :
 							 SymmetricKeyMode mode = MODE_CBC,
 							 const unsigned char * iv = NULL,
                              const unsigned char* tag = NULL,
-                             unsigned int taglen = NULL);
+                             unsigned int taglen = 0U);
 
 	/**
 	 * \brief Continue an decrypt operation using this key.
