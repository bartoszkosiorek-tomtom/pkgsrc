# $NetBSD: Makefile,v 1.26 2020/08/31 18:11:55 wiz Exp $
#

DISTNAME=		String-Approx-3.28
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/String-Approx
COMMENT=		Approximate (fuzzy) string matching library for Perl
LICENSE=		artistic-2.0 OR gnu-lgpl-v2

PERL5_PACKLIST=		auto/String/Approx/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
