# $NetBSD: Makefile,v 1.28 2020/05/19 13:59:02 joerg Exp $

.include "Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/myhdl/MyHDL/}
PKGREVISION=	2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Hardware description in Python

PYTHON_VERSIONED_DEPENDENCIES=	test:test

.include "../../lang/python/pyversion.mk"

# Python 2.x only -- subprocess is part of Python 3.x
.if ${_PYTHON_VERSION} < 32
BUILD_DEPENDS+=	${PYPKGPREFIX}-subprocess32-[0-9]*:../../devel/py-subprocess32
.endif

do-test:
	${RUN} cd ${WRKSRC}/myhdl/test/core && \
		${SETENV} ${TEST_ENV} \
		PYTHONPATH=${DESTDIR}${PREFIX}/${PYSITELIB} \
			py.test-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
