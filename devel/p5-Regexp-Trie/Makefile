# $NetBSD: Makefile,v 1.4 2020/08/31 18:08:46 wiz Exp $

DISTNAME=	Regexp-Trie-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Regexp/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Regexp-Trie
COMMENT=	Builds trie-ized regexp
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Regexp/Trie/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
