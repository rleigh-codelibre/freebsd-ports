# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

# To update this port first go to
# https://github.com/applicative-tech/stack-dependencies, change the
# version in the Makefile there, regenerate the stack-dependencies
# tarball, commit Makefile changes, create a new tag (release)
# matching the new stack version, and upload the tarball.  Finally
# bump the version here.

PORTNAME=	stack
PORTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	devel haskell
MASTER_SITES=	GH \
		https://github.com/applicative-tech/stack-dependencies/releases/download/${PORTVERSION}/:deps
DISTFILES=	stack-dependencies-${PORTVERSION}${EXTRACT_SUFX}:deps

MAINTAINER=	t@tobik.me
COMMENT=	Cross-platform program for developing Haskell programs

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	ghc>0:lang/ghc \
		cabal:devel/hs-cabal-install
LIB_DEPENDS=	libiconv.so:converters/libiconv \
		libgmp.so:math/gmp \
		libffi.so:devel/libffi
# Some (all?) GHC binaries downloaded by stack are compiled for
# FreeBSD 8 and require that gcc and libutil.so.8 are available
RUN_DEPENDS+=	gcc:lang/gcc
LIB_DEPENDS+=	libutil.so.8:misc/compat8x

# Needed for 'stack setup'
RUN_DEPENDS+=	ca_root_nss>0:security/ca_root_nss \
		gmake:devel/gmake
USES=		gmake perl5

USE_GITHUB=	yes
GH_ACCOUNT=	applicative-tech
GH_PROJECT=	stack-dependencies

MAKE_ENV+=	TARGET="${WRKSRC}" \
		PREFIX="${PREFIX}" \
		STAGEDIR="${STAGEDIR}"

PLIST_FILES=	bin/stack \
		etc/bash_completion.d/_stack.bash \
		share/zsh/site-functions/_stack

.include <bsd.port.mk>
