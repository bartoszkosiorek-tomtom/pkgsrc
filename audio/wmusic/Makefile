# $NetBSD: Makefile,v 1.26 2017/09/06 10:40:25 wiz Exp $

DISTNAME=	wmusic-1.5.0
PKGREVISION=	6
CATEGORIES=	audio windowmaker
#MASTER_SITES=	http://home.jtan.com/~john/wmusic/

MAINTAINER=	joel@carnat.net
#HOMEPAGE=	http://home.jtan.com/~john/wmusic/
COMMENT=	WindowMaker dockable remote for XMMS
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/wmusic ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/wmusic
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/wmusic
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/wmusic

.include "../../audio/xmms/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
