# $NetBSD: Makefile,v 1.19 2020/08/31 18:07:56 wiz Exp $

DISTNAME=	Eval-Closure-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DO/DOY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Eval-Closure
COMMENT=	Safely and cleanly create closures via string eval
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny

# for make test
BUILD_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
BUILD_DEPENDS+=	p5-Devel-LexAlias-[0-9]*:../../devel/p5-Devel-LexAlias

PERL5_PACKLIST=		auto/Eval/Closure/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
