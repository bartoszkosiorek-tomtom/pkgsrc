# $NetBSD: Makefile,v 1.14 2020/01/18 23:35:50 rillig Exp $

DISTNAME=		libXScrnSaver-1.2.3
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X11 Screen Saver Library

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	xscrnsaver.pc.in

CONFIGURE_ARGS.NetBSD+=	--disable-malloc0returnsnull

.include "../../meta-pkgs/modular-xorg/hacks.mk"

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
