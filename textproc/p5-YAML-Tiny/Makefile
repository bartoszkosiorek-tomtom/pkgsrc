# $NetBSD: Makefile,v 1.31 2020/08/31 18:12:15 wiz Exp $

DISTNAME=	YAML-Tiny-1.73
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	perl5 textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=YAML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/YAML-Tiny
COMMENT=	Read/Write YAML files with as little code as possible
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/YAML/Tiny/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
