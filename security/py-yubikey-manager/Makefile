#	$NetBSD: Makefile,v 1.2 2020/08/18 13:37:50 riastradh Exp $

.include "../../security/ykman/version.mk"

DISTNAME=	yubikey-manager-${VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=Yubico/}
GITHUB_PROJECT=	yubikey-manager
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developers.yubico.com/yubikey-manager/
COMMENT=	Yubico YubiKey manager library
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-click>=0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-cryptography>=0:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-fido2>=0:../../security/py-fido2
DEPENDS+=	${PYPKGPREFIX}-scard>=0:../../devel/py-scard
DEPENDS+=	${PYPKGPREFIX}-six>=0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-usb>=0:../../devel/py-usb

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ykman ykman-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../security/ykpers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
