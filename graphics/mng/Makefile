# $NetBSD: Makefile,v 1.43 2017/09/03 08:36:55 wiz Exp $

DISTNAME=	libmng-2.0.3
PKGNAME=	${DISTNAME:S/lib//}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libmng/}
#MASTER_SITES+=	http://www.libmng.com/download/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.libmng.com/
COMMENT=	Multiple-image Network Graphics (MNG) reference library

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--with-jpeg=${JPEGBASE}
CONFIGURE_ARGS+=	--with-lcms2

DOCDIR=			${PREFIX}/share/doc/mng

PKGCONFIG_OVERRIDE=	libmng.pc.in

INSTALLATION_DIRS=	${DOCDIR}

post-install:
	cd ${WRKSRC}/doc && \
		${INSTALL_DATA} Plan1.png Plan2.png libmng.txt ${DESTDIR}${DOCDIR}

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
