# $NetBSD: Makefile,v 1.18 2020/08/31 18:12:01 wiz Exp $

DISTNAME=	Text-Diff-Parser-0.1001
PKGNAME=	p5-${DISTNAME:S/1001/10.01/}
PKGREVISION=	11
CATEGORIES=	perl5 textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-Diff-Parser
COMMENT=	Parse patch files containing unified and standard diffs
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Text/Diff/Parser/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
