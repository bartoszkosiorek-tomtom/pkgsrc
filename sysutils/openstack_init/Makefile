# $NetBSD: Makefile,v 1.5 2019/05/10 22:28:47 mef Exp $
#

DISTNAME=	openstack_init-1.0
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Autoconfigure NetBSD VM on OpenStack
LICENSE=	original-bsd

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USE_LANGUAGES=	# none
REPLACE_PYTHON=	openstack_init.py xen_network.py

do-extract:
	cd ${FILESDIR} && cp *.py *.sh ${WRKSRC}/

RCD_SCRIPTS=	xen_network openstack_init

do-install:
	${INSTALL_PROGRAM_DIR}	${DESTDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/xen_network.py ${DESTDIR}${PREFIX}/sbin/
	${INSTALL_SCRIPT} ${WRKSRC}/openstack_init.py ${DESTDIR}${PREFIX}/sbin/

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
