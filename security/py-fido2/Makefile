#	$NetBSD: Makefile,v 1.1 2020/08/17 07:01:33 riastradh Exp $

DISTNAME=	fido2-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=Yubico/}
GITHUB_PROJECT=	python-fido2
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developers.yubico.com/python-fido2/
COMMENT=	Yubico FIDO U2F and FIDO 2.0 USB Python library
LICENSE=	2-clause-bsd AND apache-2.0 AND mpl-2.0

DEPENDS+=	${PYPKGPREFIX}-cryptography>=1.5:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-six>=0:../../lang/py-six

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
