# $NetBSD: Makefile,v 1.21 2020/08/31 18:12:07 wiz Exp $

DISTNAME=	XML-AutoWriter-0.4
PKGNAME=	p5-${DISTNAME}0
PKGREVISION=	11
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/XML-AutoWriter
COMMENT=	DOCTYPE-driven valid XML output
#LICENSE=	gnu-gpl-v2 OR artistic or bsd # see changes

MAKE_ENV+=		PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=		auto/XML/AutoWriter/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
