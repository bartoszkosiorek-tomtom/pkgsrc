# $NetBSD: Makefile,v 1.16 2019/10/30 15:09:03 taca Exp $

DISTNAME=	RubyInline-3.12.5
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/^Ruby//:tl}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.zenspider.com/ZSS/Products/RubyInline/
COMMENT=	Embed C/C++ code directly in Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-ZenTest>=4.3<5:../../devel/ZenTest

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
