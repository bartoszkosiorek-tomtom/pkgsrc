# $NetBSD: Makefile,v 1.15 2020/08/31 18:08:24 wiz Exp $
#

DISTNAME=	Module-Manifest-1.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Module-Manifest
COMMENT=	Parse and examine a Perl distribution MANIFEST file
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-Warn>=0.11:../../devel/p5-Test-Warn

DEPENDS+=	p5-Params-Util>=0.10:../../devel/p5-Params-Util

USE_LANGUAGES=	# empty
MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/Module/Manifest/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
