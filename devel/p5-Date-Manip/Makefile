# $NetBSD: Makefile,v 1.79 2020/08/31 18:07:49 wiz Exp $

DISTNAME=	Date-Manip-6.82
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Date-Manip
COMMENT=	Perl5 module for date calculations
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod
DEPENDS+=	p5-Test-Pod-Coverage-[0-9]*:../../devel/p5-Test-Pod-Coverage
DEPENDS+=	p5-YAML-Syck-[0-9]*:../../textproc/p5-YAML-Syck
#
TEST_DEPENDS+=	p5-Test-Inter-[0-9]*:../../devel/p5-Test-Inter
TEST_DEPENDS+=	p5-File-Find-Rule-[0-9]*:../../devel/p5-File-Find-Rule

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Date/Manip/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
