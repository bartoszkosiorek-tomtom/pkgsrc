# $NetBSD: Makefile,v 1.8 2020/08/12 19:14:22 ryoon Exp $
#

DISTNAME=	SKK-JISYO.L.${SKKJISYO_VERS}
PKGNAME=	skk-jisyo-cdb-${SKKJISYO_VERS}
CATEGORIES=	japanese inputmethod
MASTER_SITES=	${MASTER_SITE_FREEBSD_LOCAL:=matusita/skk-jisyo/}
EXTRACT_SUFX=	.gz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://openlab.ring.gr.jp/skk/wiki/wiki.cgi?page=SKK%BC%AD%BD%F1
COMMENT=	Dictionary collection for SKK
LICENSE=	gnu-gpl-v2

WRKSRC=	${WRKDIR}

BUILD_DEPENDS+=	tinycdb-[0-9]*:../../databases/tinycdb

USE_LANGUAGES=	# empty

SKKJISYO_VERS=	20200809

INSTALLATION_DIRS+=	${PREFIX}/share/skk

do-build:
	LC_ALL=C ${AWK} '/^[^;]/ { \
			s = substr($$0, index($$0, " ") + 1); \
			print "+" length($$1) "," length(s) ":" $$1 "->" s; \
		} \
		END { \
			print ""; \
		}' \
		< ${WRKDIR}/SKK-JISYO.L.${SKKJISYO_VERS} | \
	${LOCALBASE}/bin/cdb -c -t - \
		${WRKDIR}/SKK-JISYO.L.${SKKJISYO_VERS}.cdb


do-install:
	${INSTALL_DATA} ${WRKDIR}/SKK-JISYO.L.${SKKJISYO_VERS}.cdb \
		${DESTDIR}${PREFIX}/share/skk/SKK-JISYO.L.cdb

.include "../../mk/bsd.pkg.mk"
