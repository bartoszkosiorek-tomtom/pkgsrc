# $NetBSD: Makefile,v 1.11 2020/09/14 16:25:22 taca Exp $

DISTNAME=	pathname2-1.8.3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/djberg96/pathname2
COMMENT=	Alternate implementation of the Pathname library
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-facade>=1.0.4:../../devel/ruby-facade

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
