# $NetBSD: Makefile,v 1.7 2020/01/18 23:34:03 rillig Exp $

DISTNAME=	elsarticle
PKGNAME=	tex-${DISTNAME}-3.2
TEXLIVE_REV=	50786

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/elsarticle
COMMENT=	Class for articles for submission to Elsevier journals
LICENSE=	lppl-1.2

DEPENDS+=	tex-geometry-[0-9]*:../../print/tex-geometry
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-natbib-[0-9]*:../../print/tex-natbib
DEPENDS+=	tex-psnfss-[0-9]*:../../fonts/tex-psnfss
DEPENDS+=	tex-times-[0-9]*:../../fonts/tex-times
DEPENDS+=	tex-txfonts-[0-9]*:../../fonts/tex-txfonts

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
