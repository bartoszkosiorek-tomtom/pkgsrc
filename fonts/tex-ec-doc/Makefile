# $NetBSD: Makefile,v 1.4 2019/12/06 19:29:53 markd Exp $

DISTNAME=	ec.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.0
TEXLIVE_REV=	15878
DIST_SUBDIR=	tex-${DISTNAME:S/.doc//}-${TEXLIVE_REV}.2010

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-ec

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
