# $NetBSD: Makefile,v 1.7 2019/11/03 11:45:51 rillig Exp $

DISTNAME=	radiusclient-ng-0.5.5.1
CATEGORIES=	net
MASTER_SITES=	http://download.berlios.de/radiusclient-ng/

MAINTAINER=	bouyer@NetBSD.org
COMMENT=	Client library and basic utilities for Radius authenticated login
#HOMEPAGE=	http://developer.berlios.de/projects/radiusclient-ng/

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

PKG_SYSCONFSUBDIR=	radiusclient-ng
EGDIR=			${PREFIX}/share/examples/radiusclient-ng

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR:Q}

EGFILES=	issue port-id-map radiusclient.conf  dictionary dictionary.ascend \
		dictionary.compat dictionary.merit  dictionary.sip
.for f in ${EGFILES}
CONF_FILES+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

.include "../../mk/bsd.pkg.mk"
