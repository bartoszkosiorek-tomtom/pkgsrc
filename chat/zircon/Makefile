# $NetBSD: Makefile,v 1.21 2020/01/26 17:30:49 rillig Exp $
#

DISTNAME=	zircon-1.18.256
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	ftp://catless.ncl.ac.uk/pub/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://catless.ncl.ac.uk/Programs/Zircon/
COMMENT=	X11 interface to Internet Relay Chat
LICENSE=	original-bsd

NO_CONFIGURE=	yes
NO_BUILD=	yes

USE_TOOLS+=	wish:run tclsh sed

post-extract:
	@${SED} -e 's|.8.4|.8.6|' ${WRKSRC}/installer/file84.tcl > ${WRKSRC}/installer/file86.tcl
	@${SED} -e 's|.8.4|.8.6|' ${WRKSRC}/lib/tcl84.tcl > ${WRKSRC}/lib/tcl86.tcl
	@${ECHO_MSG} 'package ifneeded unixfile 1.18.8.6 [list source [file join $$dir file86.tcl]]' \
		>> ${WRKSRC}/installer/pkgIndex.tcl

do-install:
	@( cd ${WRKSRC} && ${TCLSH} installer/install.tcl -b ${PREFIX}/bin -l ${PREFIX}/share/zircon -p ${DESTDIR} -w ${WISH} -g)
	@${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/zircon
.for file in BUGS COPYRIGHT FAQ MANUAL MIRRORS README.ONS README.load README.look README.prefs TODO
	@${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DESTDIR}${PREFIX}/share/doc/zircon
.endfor

.include "../../mk/bsd.pkg.mk"
