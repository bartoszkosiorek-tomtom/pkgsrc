# $NetBSD: Makefile,v 1.22 2019/04/25 07:33:27 maya Exp $

DISTNAME=	loggerhead-${VER}
PKGREVISION=	2
CATEGORIES=	www scm
MASTER_SITES=	http://launchpad.net/loggerhead/1.18/${VER}/+download/
VER=		1.18.1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/loggerhead
COMMENT=	Web viewer for Bazaar branches
LICENSE=	gnu-gpl-v2 # or later

DEPENDS+=	bzr>=1.17:../../devel/bzr
DEPENDS+=	${PYPKGPREFIX}-flup-[0-9]*:../../www/py-flup
DEPENDS+=	${PYPKGPREFIX}-simplejson>=2.0:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-paste>=1.2:../../www/py-paste
DEPENDS+=	${PYPKGPREFIX}-PasteDeploy>=1.3:../../www/py-PasteDeploy
DEPENDS+=	${PYPKGPREFIX}-SimpleTAL>=4.1:../../www/py-simpletal

PYTHON_VERSIONS_ACCEPTED=	27 # py-simpletal

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
