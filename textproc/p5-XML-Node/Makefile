# $NetBSD: Makefile,v 1.39 2020/08/31 18:12:11 wiz Exp $

DISTNAME=	XML-Node-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	12
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://belmont-shores.ics.uci.edu/XML::Node/
COMMENT=	Node-based XML parsing: an simplified interface to XML::Parser

PERL5_PACKLIST=		auto/XML/Node/.packlist

REPLACE_PERL=	parse-orders.pl parse-foo.pl parse-testsuite.pl

post-install:
	${INSTALL_DATA} \
		${WRKSRC}/orders.xml \
		${WRKSRC}/test.xml \
		${WRKSRC}/foo.xml \
		${WRKSRC}/README \
		${DESTDIR}${PERL5_INSTALLVENDORLIB}/XML

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
