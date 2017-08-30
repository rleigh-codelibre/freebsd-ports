# Created by: gahr
# $FreeBSD$

PORTNAME=	xerces-c
PORTVERSION=	3.2.0
CATEGORIES=	textproc
MASTER_SITES=	APACHE/xerces/c/3/sources
PKGNAMESUFFIX=	3

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Validating XML parser from the Apache XML Project

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

CMAKE_ARGS=	-Dnetaccessor=socket \
		-Dtranscoder=iconv \
		-Dpkgconfig-dir=${PREFIX}/libdata/pkgconfig
INSTALL_TARGET=	install/strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOXYGEN
OPTIONS_SUB=	yes

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen \
			dot:graphics/graphviz

USES=		cmake:outsource compiler:c++11-lang cpe iconv pathfix tar:xz

LIB_DEPENDS+=	libcurl.so:ftp/curl

PLIST_SUB=	MAJOR_VER=${PORTVERSION:R}

CPE_PRODUCT=	xerces-c++
CPE_VENDOR=	apache

post-install:
	${LN} -s libxerces-c-${PORTVERSION:R}.so ${STAGEDIR}${PREFIX}/lib/libxerces-c.so.${PORTVERSION:R:R}

.include <bsd.port.mk>
