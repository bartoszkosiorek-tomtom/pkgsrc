# $NetBSD: Makefile,v 1.12 2018/02/27 23:56:09 khorben Exp $
#

DISTNAME=	urjtag-0.10
PKGREVISION=	4
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=urjtag/urjtag/0.10/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.urjtag.org/
COMMENT=	JTAG tool
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c99
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt
REPLACE_SH=		src/bsdl2jtag

post-extract:
	${CP} ${FILESDIR}/usbprog.c ${WRKSRC}/src/tap/cable

.include "../../mk/readline.buildlink3.mk"
.include "../../mk/libusb.buildlink3.mk"
.include "../../devel/libftdi/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
