# $FreeBSD$

PORTNAME=	APCu
PORTVERSION=	5.1.5
CATEGORIES=	devel
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	php70-
DISTNAME=	${PORTNAME:tl}-${PORTVERSION}
DIST_SUBDIR=	PECL

MAINTAINER=	daniel@blodan.se
COMMENT=	APC User Caching

LICENSE=	PHP301

CONFLICTS=	pecl-APC-[0-9]*

IGNORE_WITH_PHP=	55 56
USES=		localbase php:ext tar:tgz
PHP_MODNAME=	${PORTNAME:tl}

.include <bsd.port.mk>
