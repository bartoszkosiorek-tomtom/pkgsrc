# $NetBSD: Makefile,v 1.17 2020/05/17 20:18:35 adam Exp $

DISTNAME=	Flask-1.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://flask.pocoo.org/
COMMENT=	Python web microframework
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-click>=5.1:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-itsdangerous>=0.24:../../security/py-itsdangerous
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.10.1:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-werkzeug>=0.15:../../www/py-werkzeug

PYTHON_VERSIONED_DEPENDENCIES=	test:test

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} flask flask-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC}/tests && pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
