--- xsec/tools/checksig/InteropResolver.cpp.orig	2017-09-03 19:03:40 UTC
+++ xsec/tools/checksig/InteropResolver.cpp
@@ -645,7 +645,7 @@ XSECCryptoKey * InteropResolver::resolve
 
 	}
 
-	return false;
+	return 0;
 
 }
 
