# $NetBSD: Makefile,v 1.41 2020/01/26 17:32:05 rillig Exp $

DISTNAME=	opencdk-0.6.6
PKGREVISION=	3
CATEGORIES=	security devel
MASTER_SITES=	ftp://ftp.gnutls.org/pub/gnutls/attic/opencdk/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnutls.org/
COMMENT=	Open Crypto Development Kit
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
TEST_TARGET=		check

NOT_FOR_COMPILER=	xlc

REPLACE_PERL=		doc/gdoc

EGDIR=		${PREFIX}/share/examples/opencdk
HTMLDIR=	${PREFIX}/share/doc/opencdk

PKGCONFIG_OVERRIDE=	src/opencdk.pc.in

INSTALLATION_DIRS=	${HTMLDIR} ${EGDIR}

LIBS.SunOS+=	-lnsl

pre-install:
	${INSTALL_DATA}	${WRKSRC}/doc/opencdk-api.html ${DESTDIR}${HTMLDIR}
	cd ${WRKSRC}/tests && ${INSTALL_DATA} *.gpg *.c ${DESTDIR}${EGDIR}

.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgcrypt+=	libgcrypt>=1.2.2
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
