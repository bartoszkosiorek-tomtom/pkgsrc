# $NetBSD: Makefile,v 1.7 2020/07/01 14:20:46 adam Exp $

DISTNAME=	wcwidth-0.2.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wcwidth/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/jquast/wcwidth
COMMENT=	Measures number of Terminal column cells of wide-character codes
LICENSE=	mit

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-backports.functools_lru_cache>=1.2.1:../../devel/py-backports.functools_lru_cache
.endif

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
