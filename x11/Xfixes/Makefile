# $NetBSD: Makefile,v 1.33 2020/01/18 23:35:46 rillig Exp $

DISTNAME=		libXfixes-2.0.1
PKGNAME=		${DISTNAME:S/libX/X/}
PKGREVISION=		5
CATEGORIES=		x11 devel
MASTER_SITES=		https://xlibs.freedesktop.org/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://freedesktop.org/
COMMENT=		X Fixes extension of X RandR

CONFLICTS+=		libXfixes-[0-9]*

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	xfixes.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} != "native"
PKG_FAIL_REASON+=	"This package is for native X11 only; use libXfixes instead."
.endif

CFLAGS.Darwin+=	-fno-common

.include "../../x11/fixesproto4/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
