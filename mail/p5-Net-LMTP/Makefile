# $NetBSD: Makefile,v 1.20 2020/08/31 18:10:06 wiz Exp $
#

DISTNAME=	Net-LMTP-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/LHOWARD/${DISTNAME}
COMMENT=	Local Mail Transfer Protocol Client

PERL5_PACKLIST=	auto/Net/LMTP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
