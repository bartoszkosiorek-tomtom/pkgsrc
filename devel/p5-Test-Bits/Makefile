# $NetBSD: Makefile,v 1.4 2020/09/04 14:20:28 wiz Exp $

DISTNAME=	Test-Bits-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-Bits
COMMENT=	Provides a bits_is() subroutine for testing binary data
LICENSE=	artistic-2.0

DEPENDS+=	p5-List-AllUtils-[0-9]*:../../devel/p5-List-AllUtils
TEST_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal

PERL5_PACKLIST=	auto/Test/Bits/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
