# $NetBSD: Makefile,v 1.25 2020/08/31 18:08:09 wiz Exp $
#

DISTNAME=	Hook-LexWrap-0.26
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Hook/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Hook-LexWrap
COMMENT=	Perl5 module providing lexically scoped subroutine wrappers
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Hook/LexWrap/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
