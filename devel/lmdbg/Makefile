# $NetBSD: Makefile,v 1.18 2020/05/22 05:58:51 rillig Exp $
#

DISTNAME=	lmdbg-1.2.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lmdbg/}
MASTER_SITES+=	http://mova.org/~cheusov/pub/lmdbg/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/lmdbg/
COMMENT=	Lightweight Modular malloc Debugger
LICENSE=	mit

BUILD_DEPENDS+=		mk-configure>=0.24.0:../../devel/mk-configure
DEPENDS+=		pipestatus-[0-9]*:../../devel/pipestatus
DEPENDS+=		runawk>=1.3.1:../../lang/runawk
#DEPENDS+=		gdb-[0-9]*:../../devel/gdb

ONLY_FOR_COMPILER=	gcc icc clang
BROKEN_ON_PLATFORM=	Darwin-*-*

TEST_TARGET=		test

REPLACE_SH=		scripts/lmdbg*.in test/test.sh

REPLACE_INTERPRETER+=	runawk
REPLACE.runawk.old=	.*runawk
REPLACE.runawk.new=	${PREFIX}/bin/runawk
REPLACE_FILES.runawk=	scripts/lmdbg-*.in

MAKE_ENV+=		AWK=${AWK:Q}

post-install:
	cd ${WRKSRC} && \
	${MAKE_ENV} ${MAKE_PROGRAM} ${INSTALL_MAKE_FLAGS} install-doc

.include "../../devel/mk-configure/mk-c.mk"
.include "../../devel/libjudy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
