# $NetBSD: Makefile,v 1.25 2020/05/21 06:19:59 adam Exp $

DISTNAME=	httplib2-0.18.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/httplib2/}

MAINTAINER=	mj@mjturner.net
HOMEPAGE=	https://github.com/httplib2/httplib2
COMMENT=	Comprehensive http client library for Python
LICENSE=	mit

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
do-test:
.if ${_PYTHON_VERSION} == 27
	cd ${WRKSRC}/python2 && ${PYTHONBIN} httplib2test.py
.else
	cd ${WRKSRC}/python3 && ${PYTHONBIN} httplib2test.py
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
