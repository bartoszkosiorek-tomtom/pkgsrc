# $NetBSD: Makefile,v 1.18 2020/08/31 18:12:56 wiz Exp $

DISTNAME=	HTTP-Parser-XS-0.17
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTTP-Parser-XS
COMMENT=	Perl 5 module providing a fast, primitive HTTP request parser
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		c
MAKE_ENV+=		PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=		auto/HTTP/Parser/XS/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
