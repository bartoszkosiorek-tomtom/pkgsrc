# $NetBSD: Makefile,v 1.5 2020/08/17 21:21:48 leot Exp $

DISTNAME=	stagit-gopher-0.9.4
CATEGORIES=	net
MASTER_SITES=	https://codemadness.org/releases/stagit-gopher/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://codemadness.org/git/stagit-gopher/file/README.html
COMMENT=	Static git page generator for gopher
LICENSE=	mit

USE_LANGUAGES=	c99

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=	LIBGIT_INC=
MAKE_FLAGS+=	LIBGIT_LIB=-lgit2

.include "../../devel/libgit2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
