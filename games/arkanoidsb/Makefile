# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	arkanoidsb
PORTVERSION=	1.3.2.10
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.tinyorange.com/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Arkanoid and space game

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		linux tar:bzip2
NO_BUILD=	yes
USE_LINUX=	libogg sdlmixer sdlimage

SUB_FILES=	${PORTNAME}.sh

PORTDOCS=	README
OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="Arkanoid: Space Ball" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} res ${STAGEDIR}${DATADIR})
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
