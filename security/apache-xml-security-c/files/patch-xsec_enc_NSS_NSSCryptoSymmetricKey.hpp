--- xsec/enc/NSS/NSSCryptoSymmetricKey.hpp.orig	2017-09-03 18:52:39 UTC
+++ xsec/enc/NSS/NSSCryptoSymmetricKey.hpp
@@ -149,7 +149,7 @@ public :
 							 SymmetricKeyMode mode = MODE_CBC,
 							 const unsigned char * iv = NULL,
                              const unsigned char* tag = NULL,
-                             unsigned int taglen = NULL);
+                             unsigned int taglen = 0U);
 
 	/**
 	 * \brief Continue an decrypt operation using this key.
