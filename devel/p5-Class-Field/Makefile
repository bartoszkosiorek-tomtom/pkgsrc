# $NetBSD: Makefile,v 1.16 2020/08/31 18:07:37 wiz Exp $

DISTNAME=	Class-Field-0.24
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Class-Field
COMMENT=	Perl 5 class field accessor generator
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Class/Field/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
