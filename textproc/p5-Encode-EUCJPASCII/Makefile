# $NetBSD: Makefile,v 1.6 2020/09/04 09:29:11 wiz Exp $

DISTNAME=	Encode-EUCJPASCII-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Encode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Encode-EUCJPASCII
COMMENT=	eucJP-ascii - An eucJP-open mapping
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Encode/EUCJPASCII/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
