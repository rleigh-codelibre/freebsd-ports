--- xsec/enc/OpenSSL/OpenSSLCryptoSymmetricKey.hpp.orig	2017-09-03 18:59:26 UTC
+++ xsec/enc/OpenSSL/OpenSSLCryptoSymmetricKey.hpp
@@ -151,7 +151,7 @@ public :
 							 SymmetricKeyMode mode = MODE_CBC,
 							 const unsigned char * iv = NULL,
                              const unsigned char* tag = NULL,
-                             unsigned int taglen = NULL);
+                             unsigned int taglen = 0U);
 
 	/**
 	 * \brief Continue an decrypt operation using this key.
