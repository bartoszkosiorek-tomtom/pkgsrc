# $NetBSD: Makefile,v 1.32 2020/01/18 23:35:18 rillig Exp $

DISTNAME=	libpciaccess-0.16
CATEGORIES=	sysutils x11
MASTER_SITES=	${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	PCI access utility library from X.org
LICENSE=	mit AND x11

DEPENDS+=	pciids-[0-9]*:../../misc/pciids

BROKEN_ON_PLATFORM+=	Darwin-*

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-zlib
CONFIGURE_ARGS+=	--with-pciids-path=${PREFIX}/share/pciids
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	pciaccess.pc.in

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
