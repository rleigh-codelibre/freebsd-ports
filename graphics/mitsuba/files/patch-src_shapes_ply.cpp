--- src/shapes/ply.cpp.orig	2017-09-06 21:13:57 UTC
+++ src/shapes/ply.cpp
@@ -26,11 +26,7 @@
 #if MTS_USE_BOOST_TR1
 #include <boost/tr1/functional.hpp>
 #else
-#if defined(_MSC_VER) && (_MSC_VER >= 1600)
 #include <functional>
-#else
-#include <tr1/functional>
-#endif
 #endif
 
 #if !MTS_USE_BOOST_TR1 && defined(_MSC_VER) && (_MSC_VER >= 1600)
@@ -39,7 +35,7 @@
 # define PLY_USE_NULLPTR 0
 #endif
 
-using namespace std::tr1::placeholders;
+using namespace std::placeholders;
 
 MTS_NAMESPACE_BEGIN
 
@@ -160,42 +156,42 @@ public:
 			message.c_str());
 	}
 
-	template<typename ValueType> std::tr1::function <void (ValueType)>
+	template<typename ValueType> std::function <void (ValueType)>
 		scalar_property_definition_callback(const std::string& element_name,
 		const std::string& property_name);
 
-	template<typename SizeType, typename IndexType> std::tr1::tuple<std::tr1::function<void (SizeType)>,
-		std::tr1::function<void (IndexType)>, std::tr1::function<void ()> >
+	template<typename SizeType, typename IndexType> std::tuple<std::function<void (SizeType)>,
+		std::function<void (IndexType)>, std::function<void ()> >
 		list_property_definition_callback(const std::string& element_name,
 		const std::string& property_name);
 
-	std::tr1::tuple<std::tr1::function<void()>, std::tr1::function<void()> >
+	std::tuple<std::function<void()>, std::function<void()> >
 		element_definition_callback(const std::string& element_name, std::size_t count) {
 		if (element_name == "vertex") {
 			m_vertexCount = count;
 			m_positions = new Point[m_vertexCount];
-			return std::tr1::tuple<std::tr1::function<void()>,
-				std::tr1::function<void()> >(
-					std::tr1::bind(&PLYLoader::vertex_begin_callback, this),
-					std::tr1::bind(&PLYLoader::vertex_end_callback, this)
+			return std::tuple<std::function<void()>,
+				std::function<void()> >(
+					std::bind(&PLYLoader::vertex_begin_callback, this),
+					std::bind(&PLYLoader::vertex_end_callback, this)
 			);
 		} else if (element_name == "face") {
 			m_faceCount = count;
 			m_triangles = new Triangle[m_faceCount*2];
-			return std::tr1::tuple<std::tr1::function<void()>,
-				std::tr1::function<void()> >(
-				std::tr1::bind(&PLYLoader::face_begin_callback, this),
-				std::tr1::bind(&PLYLoader::face_end_callback, this)
+			return std::tuple<std::function<void()>,
+				std::function<void()> >(
+				std::bind(&PLYLoader::face_begin_callback, this),
+				std::bind(&PLYLoader::face_end_callback, this)
 			);
 		} else {
 #if PLY_USE_NULLPTR
 			return
-				std::tr1::tuple<std::tr1::function<void()>,
-				std::tr1::function<void()> >(nullptr, nullptr);
+				std::tuple<std::function<void()>,
+				std::function<void()> >(nullptr, nullptr);
 #else
 			return
-				std::tr1::tuple<std::tr1::function<void()>,
-				std::tr1::function<void()> >(0, 0);
+				std::tuple<std::function<void()>,
+				std::function<void()> >(0, 0);
 #endif
 		}
 	}
@@ -325,42 +321,42 @@ private:
 	bool m_sRGB;
 };
 
-template<> std::tr1::function <void (ply::float32)>
+template<> std::function <void (ply::float32)>
 	PLYLoader::scalar_property_definition_callback(const std::string& element_name,
 	const std::string& property_name) {
 	if (element_name == "vertex") {
 		if (property_name == "x") {
-			return std::tr1::bind(&PLYLoader::vertex_x_callback, this,  _1);
+			return std::bind(&PLYLoader::vertex_x_callback, this,  _1);
 		} else if (property_name == "y") {
-			return std::tr1::bind(&PLYLoader::vertex_y_callback, this,  _1);
+			return std::bind(&PLYLoader::vertex_y_callback, this,  _1);
 		} else if (property_name == "z") {
-			return std::tr1::bind(&PLYLoader::vertex_z_callback, this,  _1);
+			return std::bind(&PLYLoader::vertex_z_callback, this,  _1);
 		} else if (property_name == "nx") {
 			m_hasNormals = true;
-			return std::tr1::bind(&PLYLoader::normal_x_callback, this,  _1);
+			return std::bind(&PLYLoader::normal_x_callback, this,  _1);
 		} else if (property_name == "ny") {
-			return std::tr1::bind(&PLYLoader::normal_y_callback, this,  _1);
+			return std::bind(&PLYLoader::normal_y_callback, this,  _1);
 		} else if (property_name == "nz") {
-			return std::tr1::bind(&PLYLoader::normal_z_callback, this,  _1);
+			return std::bind(&PLYLoader::normal_z_callback, this,  _1);
 		} else if (property_name == "u" || property_name == "texture_u" || property_name == "s") {
 			m_hasTexCoords = true;
-			return std::tr1::bind(&PLYLoader::texcoord_u_callback, this,  _1);
+			return std::bind(&PLYLoader::texcoord_u_callback, this,  _1);
 		} else if (property_name == "v" || property_name == "texture_v" || property_name == "t") {
-			return std::tr1::bind(&PLYLoader::texcoord_v_callback, this,  _1);
+			return std::bind(&PLYLoader::texcoord_v_callback, this,  _1);
 		} else if (property_name == "diffuse_red" || property_name == "red") {
-			return std::tr1::bind(&PLYLoader::red_callback, this,  _1);
+			return std::bind(&PLYLoader::red_callback, this,  _1);
 		} else if (property_name == "diffuse_green" || property_name == "green") {
-			return std::tr1::bind(&PLYLoader::green_callback, this,  _1);
+			return std::bind(&PLYLoader::green_callback, this,  _1);
 		} else if (property_name == "diffuse_blue" || property_name == "blue") {
-			return std::tr1::bind(&PLYLoader::blue_callback, this,  _1);
+			return std::bind(&PLYLoader::blue_callback, this,  _1);
 		}
 	} else if (element_name == "face") {
 		if (property_name == "diffuse_red" || property_name == "red") {
-			return std::tr1::bind(&PLYLoader::face_red_callback, this,  _1);
+			return std::bind(&PLYLoader::face_red_callback, this,  _1);
 		} else if (property_name == "diffuse_green" || property_name == "green") {
-			return std::tr1::bind(&PLYLoader::face_green_callback, this,  _1);
+			return std::bind(&PLYLoader::face_green_callback, this,  _1);
 		} else if (property_name == "diffuse_blue" || property_name == "blue") {
-			return std::tr1::bind(&PLYLoader::face_blue_callback, this,  _1);
+			return std::bind(&PLYLoader::face_blue_callback, this,  _1);
 		}
 	}
 #if PLY_USE_NULLPTR
@@ -370,24 +366,24 @@ template<> std::tr1::function <void (ply
 #endif
 }
 
-template<> std::tr1::function <void (ply::uint8)>
+template<> std::function <void (ply::uint8)>
 	PLYLoader::scalar_property_definition_callback(const std::string& element_name,
 	const std::string& property_name) {
 	if (element_name == "vertex") {
 		if (property_name == "diffuse_red" || property_name == "red") {
-			return std::tr1::bind(&PLYLoader::red_callback_uint8, this,  _1);
+			return std::bind(&PLYLoader::red_callback_uint8, this,  _1);
 		} else if (property_name == "diffuse_green" || property_name == "green") {
-			return std::tr1::bind(&PLYLoader::green_callback_uint8, this,  _1);
+			return std::bind(&PLYLoader::green_callback_uint8, this,  _1);
 		} else if (property_name == "diffuse_blue" || property_name == "blue") {
-			return std::tr1::bind(&PLYLoader::blue_callback_uint8, this,  _1);
+			return std::bind(&PLYLoader::blue_callback_uint8, this,  _1);
 		}
 	} else if (element_name == "face") {
 		if (property_name == "diffuse_red" || property_name == "red") {
-			return std::tr1::bind(&PLYLoader::face_red_callback_uint8, this,  _1);
+			return std::bind(&PLYLoader::face_red_callback_uint8, this,  _1);
 		} else if (property_name == "diffuse_green" || property_name == "green") {
-			return std::tr1::bind(&PLYLoader::face_green_callback_uint8, this,  _1);
+			return std::bind(&PLYLoader::face_green_callback_uint8, this,  _1);
 		} else if (property_name == "diffuse_blue" || property_name == "blue") {
-			return std::tr1::bind(&PLYLoader::face_blue_callback_uint8, this,  _1);
+			return std::bind(&PLYLoader::face_blue_callback_uint8, this,  _1);
 		}
 	}
 #if PLY_USE_NULLPTR
@@ -397,98 +393,98 @@ template<> std::tr1::function <void (ply
 #endif
 }
 
-template<> std::tr1::tuple<std::tr1::function<void (ply::uint8)>,
-	std::tr1::function<void (ply::int32)>, std::tr1::function<void ()> >
+template<> std::tuple<std::function<void (ply::uint8)>,
+	std::function<void (ply::int32)>, std::function<void ()> >
 	PLYLoader::list_property_definition_callback(const std::string& element_name,
 	const std::string& property_name) {
 	if ((element_name == "face") && (property_name == "vertex_indices" || property_name == "vertex_index")) {
-		return std::tr1::tuple<std::tr1::function<void (ply::uint8)>,
-			std::tr1::function<void (ply::int32)>, std::tr1::function<void ()> >(
-			std::tr1::bind(&PLYLoader::face_vertex_indices_begin_uint8, this, _1),
-			std::tr1::bind(&PLYLoader::face_vertex_indices_element_int32, this, _1),
-			std::tr1::bind(&PLYLoader::face_vertex_indices_end, this)
+		return std::tuple<std::function<void (ply::uint8)>,
+			std::function<void (ply::int32)>, std::function<void ()> >(
+			std::bind(&PLYLoader::face_vertex_indices_begin_uint8, this, _1),
+			std::bind(&PLYLoader::face_vertex_indices_element_int32, this, _1),
+			std::bind(&PLYLoader::face_vertex_indices_end, this)
 		);
 	} else {
 #if PLY_USE_NULLPTR
-		return std::tr1::tuple<std::tr1::function<void (ply::uint8)>,
-			std::tr1::function<void (ply::int32)>,
-			std::tr1::function<void ()> >(nullptr, nullptr, nullptr);
+		return std::tuple<std::function<void (ply::uint8)>,
+			std::function<void (ply::int32)>,
+			std::function<void ()> >(nullptr, nullptr, nullptr);
 #else
-		return std::tr1::tuple<std::tr1::function<void (ply::uint8)>,
-			std::tr1::function<void (ply::int32)>,
-			std::tr1::function<void ()> >(0, 0, 0);
+		return std::tuple<std::function<void (ply::uint8)>,
+			std::function<void (ply::int32)>,
+			std::function<void ()> >(0, 0, 0);
 #endif
 	}
 }
 
-template<> std::tr1::tuple<std::tr1::function<void (ply::uint32)>,
-	std::tr1::function<void (ply::int32)>, std::tr1::function<void ()> >
+template<> std::tuple<std::function<void (ply::uint32)>,
+	std::function<void (ply::int32)>, std::function<void ()> >
 	PLYLoader::list_property_definition_callback(const std::string& element_name,
 	const std::string& property_name) {
 	if ((element_name == "face") && (property_name == "vertex_indices" || property_name == "vertex_index")) {
-		return std::tr1::tuple<std::tr1::function<void (ply::uint32)>,
-			std::tr1::function<void (ply::int32)>, std::tr1::function<void ()> >(
-			std::tr1::bind(&PLYLoader::face_vertex_indices_begin_uint32, this, _1),
-			std::tr1::bind(&PLYLoader::face_vertex_indices_element_int32, this, _1),
-			std::tr1::bind(&PLYLoader::face_vertex_indices_end, this)
+		return std::tuple<std::function<void (ply::uint32)>,
+			std::function<void (ply::int32)>, std::function<void ()> >(
+			std::bind(&PLYLoader::face_vertex_indices_begin_uint32, this, _1),
+			std::bind(&PLYLoader::face_vertex_indices_element_int32, this, _1),
+			std::bind(&PLYLoader::face_vertex_indices_end, this)
 		);
 	} else {
 #if PLY_USE_NULLPTR
-		return std::tr1::tuple<std::tr1::function<void (ply::uint32)>,
-			std::tr1::function<void (ply::int32)>,
-			std::tr1::function<void ()> >(nullptr, nullptr, nullptr);
+		return std::tuple<std::function<void (ply::uint32)>,
+			std::function<void (ply::int32)>,
+			std::function<void ()> >(nullptr, nullptr, nullptr);
 #else
-		return std::tr1::tuple<std::tr1::function<void (ply::uint32)>,
-			std::tr1::function<void (ply::int32)>,
-			std::tr1::function<void ()> >(0, 0, 0);
+		return std::tuple<std::function<void (ply::uint32)>,
+			std::function<void (ply::int32)>,
+			std::function<void ()> >(0, 0, 0);
 #endif
 	}
 }
 
-template<> std::tr1::tuple<std::tr1::function<void (ply::uint8)>,
-	std::tr1::function<void (ply::uint32)>, std::tr1::function<void ()> >
+template<> std::tuple<std::function<void (ply::uint8)>,
+	std::function<void (ply::uint32)>, std::function<void ()> >
 	PLYLoader::list_property_definition_callback(const std::string& element_name,
 	const std::string& property_name) {
 	if ((element_name == "face") && (property_name == "vertex_indices" || property_name == "vertex_index")) {
-		return std::tr1::tuple<std::tr1::function<void (ply::uint8)>,
-			std::tr1::function<void (ply::uint32)>, std::tr1::function<void ()> >(
-			std::tr1::bind(&PLYLoader::face_vertex_indices_begin_uint8, this, _1),
-			std::tr1::bind(&PLYLoader::face_vertex_indices_element_uint32, this, _1),
-			std::tr1::bind(&PLYLoader::face_vertex_indices_end, this)
+		return std::tuple<std::function<void (ply::uint8)>,
+			std::function<void (ply::uint32)>, std::function<void ()> >(
+			std::bind(&PLYLoader::face_vertex_indices_begin_uint8, this, _1),
+			std::bind(&PLYLoader::face_vertex_indices_element_uint32, this, _1),
+			std::bind(&PLYLoader::face_vertex_indices_end, this)
 		);
 	} else {
 #if PLY_USE_NULLPTR
-		return std::tr1::tuple<std::tr1::function<void (ply::uint8)>,
-			std::tr1::function<void (ply::uint32)>,
-			std::tr1::function<void ()> >(nullptr, nullptr, nullptr);
+		return std::tuple<std::function<void (ply::uint8)>,
+			std::function<void (ply::uint32)>,
+			std::function<void ()> >(nullptr, nullptr, nullptr);
 #else
-		return std::tr1::tuple<std::tr1::function<void (ply::uint8)>,
-			std::tr1::function<void (ply::uint32)>,
-			std::tr1::function<void ()> >(0, 0, 0);
+		return std::tuple<std::function<void (ply::uint8)>,
+			std::function<void (ply::uint32)>,
+			std::function<void ()> >(0, 0, 0);
 #endif
 	}
 }
 
-template<> std::tr1::tuple<std::tr1::function<void (ply::uint32)>,
-	std::tr1::function<void (ply::uint32)>, std::tr1::function<void ()> >
+template<> std::tuple<std::function<void (ply::uint32)>,
+	std::function<void (ply::uint32)>, std::function<void ()> >
 	PLYLoader::list_property_definition_callback(const std::string& element_name,
 	const std::string& property_name) {
 	if ((element_name == "face") && (property_name == "vertex_indices" || property_name == "vertex_index")) {
-		return std::tr1::tuple<std::tr1::function<void (ply::uint32)>,
-			std::tr1::function<void (ply::uint32)>, std::tr1::function<void ()> >(
-			std::tr1::bind(&PLYLoader::face_vertex_indices_begin_uint32, this, _1),
-			std::tr1::bind(&PLYLoader::face_vertex_indices_element_uint32, this, _1),
-			std::tr1::bind(&PLYLoader::face_vertex_indices_end, this)
+		return std::tuple<std::function<void (ply::uint32)>,
+			std::function<void (ply::uint32)>, std::function<void ()> >(
+			std::bind(&PLYLoader::face_vertex_indices_begin_uint32, this, _1),
+			std::bind(&PLYLoader::face_vertex_indices_element_uint32, this, _1),
+			std::bind(&PLYLoader::face_vertex_indices_end, this)
 		);
 	} else {
 #if PLY_USE_NULLPTR
-		return std::tr1::tuple<std::tr1::function<void (ply::uint32)>,
-			std::tr1::function<void (ply::uint32)>,
-			std::tr1::function<void ()> >(nullptr, nullptr, nullptr);
+		return std::tuple<std::function<void (ply::uint32)>,
+			std::function<void (ply::uint32)>,
+			std::function<void ()> >(nullptr, nullptr, nullptr);
 #else
-		return std::tr1::tuple<std::tr1::function<void (ply::uint32)>,
-			std::tr1::function<void (ply::uint32)>,
-			std::tr1::function<void ()> >(0, 0, 0);
+		return std::tuple<std::function<void (ply::uint32)>,
+			std::function<void (ply::uint32)>,
+			std::function<void ()> >(0, 0, 0);
 #endif
 	}
 }
@@ -496,35 +492,35 @@ template<> std::tr1::tuple<std::tr1::fun
 
 void PLYLoader::loadPLY(const fs::path &path) {
 	ply::ply_parser ply_parser;
-	ply_parser.info_callback(std::tr1::bind(&PLYLoader::info_callback,
-		this, std::tr1::ref(m_name), _1, _2));
-	ply_parser.warning_callback(std::tr1::bind(&PLYLoader::warning_callback,
-		this, std::tr1::ref(m_name), _1, _2));
-	ply_parser.error_callback(std::tr1::bind(&PLYLoader::error_callback,
-		this, std::tr1::ref(m_name), _1, _2));
+	ply_parser.info_callback(std::bind(&PLYLoader::info_callback,
+		this, std::ref(m_name), _1, _2));
+	ply_parser.warning_callback(std::bind(&PLYLoader::warning_callback,
+		this, std::ref(m_name), _1, _2));
+	ply_parser.error_callback(std::bind(&PLYLoader::error_callback,
+		this, std::ref(m_name), _1, _2));
 
-	ply_parser.element_definition_callback(std::tr1::bind(&PLYLoader::element_definition_callback,
+	ply_parser.element_definition_callback(std::bind(&PLYLoader::element_definition_callback,
 		this, _1, _2));
 
 	ply::ply_parser::scalar_property_definition_callbacks_type scalar_property_definition_callbacks;
 	ply::ply_parser::list_property_definition_callbacks_type list_property_definition_callbacks;
 
-	ply::at<ply::float32>(scalar_property_definition_callbacks) = std::tr1::bind(
+	ply::at<ply::float32>(scalar_property_definition_callbacks) = std::bind(
 		&PLYLoader::scalar_property_definition_callback<ply::float32>, this, _1, _2);
 
-	ply::at<ply::uint8>(scalar_property_definition_callbacks) = std::tr1::bind(
+	ply::at<ply::uint8>(scalar_property_definition_callbacks) = std::bind(
 		&PLYLoader::scalar_property_definition_callback<ply::uint8>, this, _1, _2);
 
-	ply::at<ply::uint8, ply::int32>(list_property_definition_callbacks) = std::tr1::bind(
+	ply::at<ply::uint8, ply::int32>(list_property_definition_callbacks) = std::bind(
 		&PLYLoader::list_property_definition_callback<ply::uint8, ply::int32>, this, _1, _2);
 
-	ply::at<ply::uint32, ply::int32>(list_property_definition_callbacks) = std::tr1::bind(
+	ply::at<ply::uint32, ply::int32>(list_property_definition_callbacks) = std::bind(
 		&PLYLoader::list_property_definition_callback<ply::uint32, ply::int32>, this, _1, _2);
 
-	ply::at<ply::uint8, ply::uint32>(list_property_definition_callbacks) = std::tr1::bind(
+	ply::at<ply::uint8, ply::uint32>(list_property_definition_callbacks) = std::bind(
 		&PLYLoader::list_property_definition_callback<ply::uint8, ply::uint32>, this, _1, _2);
 
-	ply::at<ply::uint32, ply::uint32>(list_property_definition_callbacks) = std::tr1::bind(
+	ply::at<ply::uint32, ply::uint32>(list_property_definition_callbacks) = std::bind(
 		&PLYLoader::list_property_definition_callback<ply::uint32, ply::uint32>, this, _1, _2);
 
 	ply_parser.scalar_property_definition_callbacks(scalar_property_definition_callbacks);
