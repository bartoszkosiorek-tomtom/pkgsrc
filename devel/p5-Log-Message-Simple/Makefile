# $NetBSD: Makefile,v 1.10 2020/09/08 13:09:54 wiz Exp $

DISTNAME=	Log-Message-Simple-0.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Log::Message::Simple
COMMENT=	Simple - Simplified interface to Log::Message
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Log-Message-[0-9]*:../../devel/p5-Log-Message

PERL5_PACKLIST=	auto/Log/Message/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
