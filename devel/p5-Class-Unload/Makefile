# $NetBSD: Makefile,v 1.18 2020/08/31 18:07:40 wiz Exp $

DISTNAME=	Class-Unload-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Class-Unload
COMMENT=	Perl 5 module to unload a class
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Inspector-[0-9]*:../../devel/p5-Class-Inspector
# for make test
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires

PERL5_PACKLIST=		auto/Class/Unload/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
