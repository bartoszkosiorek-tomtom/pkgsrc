# $NetBSD: Makefile,v 1.16 2019/11/03 09:14:20 rillig Exp $
#

DISTNAME=	xkbd-0.8.5
PKGREVISION=	2
CATEGORIES=	x11
#MASTER_SITES=	http://handhelds.org/~mallum/downloadables/xkbd/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://handhelds.org/~mallum/
COMMENT=	On-screen keyboard for X, useful for palmtops

CONFIGURE_ARGS+=	--enable-xpm

GNU_CONFIGURE=	YES

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
