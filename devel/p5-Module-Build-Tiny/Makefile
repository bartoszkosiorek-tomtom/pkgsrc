# $NetBSD: Makefile,v 1.19 2020/09/04 13:37:50 wiz Exp $

DISTNAME=	Module-Build-Tiny-0.039
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/L/LE/LEONT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Module-Build-Tiny
COMMENT=	Tiny replacement for Module::Build to build and install Perl modules
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-ExtUtils-Config>=0.003:../../devel/p5-ExtUtils-Config
DEPENDS+=	p5-ExtUtils-Helpers>=0.020:../../devel/p5-ExtUtils-Helpers
DEPENDS+=	p5-ExtUtils-InstallPaths>=0.002:../../devel/p5-ExtUtils-InstallPaths

USE_LANGUAGES=		c       # For the tests
#BUILDING_MODULE_BUILD=	yes
PERL5_MODULE_TYPE=	Module::Build::Tiny
PERL5_PACKLIST=		auto/Module/Build/Tiny/.packlist
# For the tests:
USE_TOOLS+=		perl

PERL5_PACKLIST=	auto/Module/Build/Tiny/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
