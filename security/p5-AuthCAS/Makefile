# $NetBSD: Makefile,v 1.16 2020/08/31 18:11:09 wiz Exp $

DISTNAME=	AuthCAS-1.7
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/O/OS/OSALAUN/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/AuthCAS
COMMENT=	AuthCAS - Client library for CAS 2.0 authentication server
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-IO-Socket-SSL-[0-9]*:../../security/p5-IO-Socket-SSL
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

USE_LANGUAGES=		#

PERL5_PACKLIST=	auto/AuthCAS/.packlist

REPLACE_PERL+=	sampleCasClient.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
