# $NetBSD: Makefile,v 1.24 2020/09/14 15:22:55 taca Exp $

DISTNAME=	capybara-3.33.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel ruby www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jnicklas/capybara
COMMENT=	Integration testing tool for rack based web applications
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=0:../../net/ruby-addressable
DEPENDS+=	${RUBY_PKGPREFIX}-mini_mime>=0.1.3:../../mail/ruby-mini_mime
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.8:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-rack16>=1.6.0:../../www/ruby-rack16
DEPENDS+=	${RUBY_PKGPREFIX}-rack-test>=0.6.3:../../www/ruby-rack-test
DEPENDS+=	${RUBY_PKGPREFIX}-regexp_parser>=1.5<2:../../devel/ruby-regexp_parser
DEPENDS+=	${RUBY_PKGPREFIX}-xpath>=3.2:../../textproc/ruby-xpath

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
