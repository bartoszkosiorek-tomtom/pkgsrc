# $NetBSD: Makefile,v 1.4 2020/10/12 21:52:02 bacon Exp $

DISTNAME=	Bottleneck-1.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=B/Bottleneck/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kwgoodman/bottleneck
COMMENT=	Collection of fast NumPy array functions written in C
LICENSE=	2-clause-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

PYSETUPTESTTARGET=	pytest

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
