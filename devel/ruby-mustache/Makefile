# $NetBSD: Makefile,v 1.3 2020/04/27 06:03:16 taca Exp $

DISTNAME=		mustache-1.1.1
PKGNAME=		${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=		devel

MAINTAINER=		nils@NetBSD.org
HOMEPAGE=		https://mustache.github.io/
COMMENT=		Logic-less Ruby templates
LICENSE=		mit

RUBYGEM_OPTIONS+=	--format-executable

INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PKGMANDIR}/man5

post-install:
	${LN} -sf ${PREFIX}/${GEM_LIBDIR}/man/mustache.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${RUBY_PKGPREFIX}-mustache.1
	${LN} -sf ${PREFIX}/${GEM_LIBDIR}/man/mustache.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/${RUBY_PKGPREFIX}-mustache.5

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
