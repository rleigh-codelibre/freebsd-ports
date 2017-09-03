--- xsec/enc/XSECCryptoSymmetricKey.hpp.orig	2017-09-03 18:48:32 UTC
+++ xsec/enc/XSECCryptoSymmetricKey.hpp
@@ -185,7 +185,7 @@ public :
 							 SymmetricKeyMode mode = MODE_CBC,
 							 const unsigned char* iv = NULL,
                              const unsigned char* tag = NULL,
-                             unsigned int taglen = NULL) = 0;
+                             unsigned int taglen = 0U) = 0;
 
 	/**
 	 * \brief Continue a decrypt operation using this key.
