# $NetBSD: Makefile,v 1.3 2020/08/14 14:14:44 fcambus Exp $

DISTNAME=	libmaxminddb-1.4.3
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=maxmind/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://maxmind.github.io/libmaxminddb/
COMMENT=	C library for the MaxMind DB file format
LICENSE=	apache-2.0

GNU_CONFIGURE=	yes
USE_LANGUAGES+=	c99
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	src/libmaxminddb.pc.in

.include "../../mk/bsd.pkg.mk"
