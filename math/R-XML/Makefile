# $NetBSD: Makefile,v 1.13 2020/11/05 09:08:36 ryoon Exp $

R_PKGNAME=	XML
R_PKGVER=	3.98-1.20
PKGREVISION=	2
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tools for parsing and generating XML within R
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
