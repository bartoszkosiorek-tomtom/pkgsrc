# $NetBSD: Makefile,v 1.28 2020/08/31 18:12:03 wiz Exp $

DISTNAME=	Text-Reform-1.20
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	eric@cirr.com
HOMEPAGE=	https://metacpan.org/search?q=module%3AText%3A%3AReform
COMMENT=	Manual text wrapping and reformatting
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Text/Reform/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
