# $NetBSD: Makefile,v 1.11 2020/08/31 18:08:53 wiz Exp $

DISTNAME=	Sub-Quote-2.006006
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sub/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Sub-Quote
COMMENT=	Efficient generation of subroutines via string eval
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=	p5-Test-Fatal>=0.003:../../devel/p5-Test-Fatal

PERL5_PACKLIST=	auto/Sub/Quote/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
