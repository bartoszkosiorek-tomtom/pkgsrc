# $NetBSD: Makefile,v 1.11 2020/08/31 18:10:14 wiz Exp $

DISTNAME=	Math-Derivative-1.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Math-Derivative
COMMENT=	Numeric 1st and 2nd order differentiation
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Math/Derivative/.packlist

DEPENDS+=	p5-Math-Utils>=1.10:../../math/p5-Math-Utils

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
