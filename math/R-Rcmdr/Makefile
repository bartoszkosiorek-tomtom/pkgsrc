# $NetBSD: Makefile,v 1.11 2020/09/20 23:57:25 mef Exp $

R_PKGNAME=	Rcmdr
R_PKGVER=	2.7-0

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Platform-independent basic-statistics GUI for R
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-tcltk2>=1.2.6:../../devel/R-tcltk2
DEPENDS+=	R-effects>=4.0.3:../../graphics/R-effects
DEPENDS+=	R-RcmdrMisc>=2.7.1:../../math/R-RcmdrMisc
DEPENDS+=	R-abind>=1.4.5:../../math/R-abind
DEPENDS+=	R-car>=3.0.8:../../math/R-car
DEPENDS+=	R-relimp>=1.0.5:../../math/R-relimp

# Packages suggested but not available:
#   'leaps', 'multcomp', 'rgl', 'sem'
TEST_DEPENDS+=	R-aplpack-[0-9]*:../../math/R-aplpack


USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
