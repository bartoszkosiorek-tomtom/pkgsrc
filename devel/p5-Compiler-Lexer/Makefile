# $NetBSD: Makefile,v 1.2 2020/08/31 18:07:41 wiz Exp $

DISTNAME=	Compiler-Lexer-0.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Compiler/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Compiler-Lexer
COMMENT=	Lexical Analyzer for Perl5
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Module-Build-XSUtil-[0-9]*:../../devel/p5-Module-Build-XSUtil

USE_LANGUAGES=		c c++
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Compiler/Lexer/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
