# $NetBSD: Makefile,v 1.30 2020/11/12 10:40:24 adam Exp $

DISTNAME=	boto3-1.16.16
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/boto3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/boto/boto3
COMMENT=	Amazon Web Services SDK for Python
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-botocore>=1.19.16:../../net/py-botocore
DEPENDS+=	${PYPKGPREFIX}-jmespath>=0.7.1:../../textproc/py-jmespath
DEPENDS+=	${PYPKGPREFIX}-s3transfer>=0.3.0:../../net/py-s3transfer

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
