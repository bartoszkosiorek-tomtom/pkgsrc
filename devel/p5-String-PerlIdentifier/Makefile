# $NetBSD: Makefile,v 1.16 2020/08/31 18:08:52 wiz Exp $
#

DISTNAME=	String-PerlIdentifier-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/String-PerlIdentifier
COMMENT=	Generate a random name for a Perl variable
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/String/PerlIdentifier/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
