--- cegui/src/XMLParserModules/TinyXML/XMLParser.cpp.orig	2017-09-04 09:38:57.918728000 +0100
+++ cegui/src/XMLParserModules/TinyXML/XMLParser.cpp	2017-09-04 09:40:24.424412000 +0100
@@ -130,7 +130,7 @@
                 processElement(childNode->ToElement());
                 break;
             case TiXmlNode::CEGUI_TINYXML_TEXT:
-                if (childNode->ToText()->Value() != '\0')
+                if (*(childNode->ToText()->Value()) != '\0')
                     d_handler->text((encoded_char*)childNode->ToText()->Value());
                 break;
 
