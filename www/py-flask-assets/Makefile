# $NetBSD: Makefile,v 1.8 2020/05/12 16:02:16 kleink Exp $

DISTNAME=	Flask-Assets-2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-Assets/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/miracle2k/flask-assets
COMMENT=	Flask webassets integration
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

DEPENDS+=	${PYPKGPREFIX}-flask>=0.8:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-webassets>=2.0:../../www/py-webassets
TEST_DEPENDS+=	${PYPKGPREFIX}-flask-script-[0-9]*:../../www/py-flask-script
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
