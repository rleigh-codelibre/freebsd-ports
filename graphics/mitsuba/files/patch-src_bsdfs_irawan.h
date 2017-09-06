--- src/bsdfs/irawan.h.orig	2015-07-15 10:37:38 UTC
+++ src/bsdfs/irawan.h
@@ -28,9 +28,17 @@
 #include <boost/spirit/include/phoenix_operator.hpp>
 #include <boost/spirit/include/phoenix_stl.hpp>
 #include <boost/spirit/home/qi/numeric/real.hpp>
+#include <boost/version.hpp>
+
+#if BOOST_VERSION >= 105800
+#include <boost/phoenix/bind/bind_member_variable.hpp>
+#include <boost/phoenix/bind/bind_member_function.hpp>
+#include <boost/phoenix/statement/if.hpp>
+#else
 #include <boost/spirit/home/phoenix/bind/bind_member_variable.hpp>
 #include <boost/spirit/home/phoenix/bind/bind_member_function.hpp>
 #include <boost/spirit/home/phoenix/statement/if.hpp>
+#endif
 
 MTS_NAMESPACE_BEGIN
 
@@ -303,10 +311,12 @@ template <typename Iterator> struct Yarn
 
 		spec = ((lit("{") >> Float_ >> lit(",") >> Float_ >> lit(",") >> Float_ >> lit("}")) 
 					[ ph::bind(&Spectrum::fromLinearRGB, _val, _1, _2, _3, Spectrum::EReflectance) ])
-		     | (identifier [ _val = ph::bind(&Properties::getSpectrum, ph::ref(props), _1)]);
+                     | (identifier [ _val = ph::bind((Spectrum (Properties::*)(const std::string &) const)
+                                                     &Properties::getSpectrum, ph::ref(props), _1)]);
 
 		flt = (Float_ [ _val = _1 ])
-		    | (identifier [ _val = ph::bind(&Properties::getFloat, ph::ref(props), _1)]);
+                    | (identifier [ _val = ph::bind((Float (Properties::*)(const std::string &) const)
+                                                    &Properties::getFloat, ph::ref(props), _1)]);
 
 		start = lit("yarn")
 			>> lit("{")
@@ -356,7 +366,8 @@ template <typename Iterator> struct Weav
 			>> *(qi::alnum | char_('_')) ];
 
 		flt = (Float_ [ _val = _1 ])
-		      | (identifier [ _val = ph::bind(&Properties::getFloat, ph::ref(props), _1)]);
+                    | (identifier [ _val = ph::bind((Float (Properties::*)(const std::string &) const)
+                                                    &Properties::getFloat, ph::ref(props), _1)]);
 
 		start = lit("weave") >> lit("{") >> (
 			  lit("name")               >> lit("=") >> name   [ ph::bind(&WeavePattern::name,               _val) = _1  ]
