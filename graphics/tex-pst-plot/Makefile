# $NetBSD: Makefile,v 1.11 2019/12/06 20:04:34 markd Exp $

DISTNAME=	pst-plot
PKGNAME=	tex-${DISTNAME}-1.92
TEXLIVE_REV=	51650

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pst-plot
COMMENT=	Plot data using PSTricks
LICENSE=	lppl-1.3c

DEPENDS+=	tex-multido-[0-9]*:../../devel/tex-multido
DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
