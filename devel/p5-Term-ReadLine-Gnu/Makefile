# $NetBSD: Makefile,v 1.1 2020/09/06 11:54:38 wiz Exp $

DISTNAME=	Term-ReadLine-Gnu-1.36
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Term-ReadLine-Gnu
COMMENT=	Perl extension for the GNU Readline/History Library
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Term/ReadLine/Gnu/.packlist

.include "../../lang/perl5/module.mk"
# does not accept editline
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
