# $NetBSD: Makefile,v 1.5 2020/01/18 23:35:57 rillig Exp $

DISTNAME=	transset-1.0.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Utility for setting opacity property

GNU_CONFIGURE=	yes

USE_TOOLS+=	pkg-config

.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
