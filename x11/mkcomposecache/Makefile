# $NetBSD: Makefile,v 1.5 2020/01/18 23:35:54 rillig Exp $
#

DISTNAME=	mkcomposecache-1.2.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Used for creating global (system-wide) Compose cache files
#LICENSE=	# XXX SUSE license ?

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ENV.SunOS+=	ADMIN_MAN_SUFFIX=8

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
