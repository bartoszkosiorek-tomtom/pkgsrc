# $NetBSD: Makefile,v 1.46 2020/08/31 18:11:11 wiz Exp $

DISTNAME=		Crypt-CBC-2.33
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		8
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Crypt-CBC
COMMENT=		Perl5 cipher block chaining mode for various crypto algorithms

BUILD_DEPENDS+=		p5-Crypt-Rijndael-[0-9]*:../../security/p5-Crypt-Rijndael
#DEPENDS+=		{perl>=5.7.3,p5-Digest-MD5>=2.0}:../../security/p5-Digest-MD5

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Crypt/CBC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
