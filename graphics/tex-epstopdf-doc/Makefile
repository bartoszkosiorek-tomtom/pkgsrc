# $NetBSD: Makefile,v 1.9 2020/01/18 23:32:23 rillig Exp $

DISTNAME=	epstopdf.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2.28
TEXLIVE_REV=	48684

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/epstopdf
COMMENT=	Documentation for tex-epstopdf
LICENSE=	modified-bsd

CONFLICTS=	texlive-pdftools<2011

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
