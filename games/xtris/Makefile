# $NetBSD: Makefile,v 1.23 2017/10/09 08:55:36 wiz Exp $

DISTNAME=	xtris-1.15
PKGREVISION=	2
CATEGORIES=	games x11
#MASTER_SITES=	http://www.iagora.com/~espel/xtris/

MAINTAINER=	opp@MuFFiN.Org
#HOMEPAGE=	https://www.iagora.com/~espel/xtris/xtris.html
COMMENT=	Multi-player version of a popular game for the X Window system

WRKSRC=		${WRKDIR}/xtris
LIBS.SunOS+=	-lsocket -lnsl
MAKE_ENV+=	LIBS=${LIBS:Q}

SETGIDGAME=	yes
SPECIAL_PERMS+=	bin/xtris ${SETGID_GAMES_PERMS}
SPECIAL_PERMS+=	bin/xtbot ${SETGID_GAMES_PERMS}
SPECIAL_PERMS+=	bin/xtserv ${SETGID_GAMES_PERMS}

.include "options.mk"

INSTALLATION_DIRS=	bin ${PREFIX}/${PKGMANDIR}/man6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xtris ${DESTDIR}${PREFIX}/bin/xtris
	${INSTALL_PROGRAM} ${WRKSRC}/xtbot ${DESTDIR}${PREFIX}/bin/xtbot
	${INSTALL_PROGRAM} ${WRKSRC}/xtserv ${DESTDIR}${PREFIX}/bin/xtserv
	${INSTALL_MAN} ${WRKSRC}/xtris.6 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/xtris.6
	${INSTALL_MAN} ${WRKSRC}/xtbot.6 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/xtbot.6
	${INSTALL_MAN} ${WRKSRC}/xtserv.6 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/xtserv.6

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
