# $NetBSD: Makefile,v 1.57 2020/08/31 18:10:11 wiz Exp $
#

DISTNAME=		galculator-2.1.4
PKGREVISION=		6
CATEGORIES=		math
MASTER_SITES=		http://galculator.mnim.org/downloads/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://galculator.mnim.org/
COMMENT=		Desktop calculator with scientific / RPN modes
LICENSE=		gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config intltool perl
USE_TOOLS+=		msgfmt msgmerge xgettext

.include "../../x11/gtk3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
