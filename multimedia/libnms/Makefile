# $NetBSD: Makefile,v 1.5 2017/08/16 20:45:41 wiz Exp $
#

DISTNAME=	libnms-0.6.0
CATEGORIES=	multimedia
MASTER_SITES=	http://www.paldo.org/paldo/sources/libnms/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jfranz@bsdprojects.net
#HOMEPAGE=	http://streaming.polito.it/client/library/
COMMENT=	Open Media Streaming Client Library

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	libnms.pc.in

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../mk/bsd.pkg.mk"
