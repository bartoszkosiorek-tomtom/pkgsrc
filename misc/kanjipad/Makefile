# $NetBSD: Makefile,v 1.63 2020/08/31 18:10:21 wiz Exp $

DISTNAME=		kanjipad-2.0.0
PKGREVISION=		44
CATEGORIES=		misc
MASTER_SITES=		https://fishsoup.net/software/kanjipad/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://fishsoup.net/software/kanjipad/
COMMENT=		Japanese handwriting recognition

USE_TOOLS+=		gmake perl pkg-config
LDFLAGS+=		-lm	# direct link required by ld v2.22

INSTALLATION_DIRS+=	share/doc/kanjipad

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/kanjipad

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
