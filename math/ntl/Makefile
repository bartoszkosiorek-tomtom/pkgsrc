# $NetBSD: Makefile,v 1.37 2020/08/31 18:10:11 wiz Exp $

DISTNAME=		ntl-11.4.3
PKGREVISION=		1
CATEGORIES=		math devel
MASTER_SITES=		https://www.shoup.net/ntl/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.shoup.net/ntl/
COMMENT=		C++ library for doing number theory
LICENSE=		gnu-lgpl-v2.1

WRKSRC=			${WRKDIR}/${DISTNAME}/src
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	DEF_PREFIX=${PREFIX}
USE_LANGUAGES=		c c++
USE_TOOLS+=		perl
MAKE_FILE=		makefile
TEST_TARGET=		check

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
