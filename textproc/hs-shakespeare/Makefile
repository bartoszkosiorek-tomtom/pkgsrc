# $NetBSD: Makefile,v 1.2 2020/04/03 07:25:43 wiz Exp $

DISTNAME=	shakespeare-2.0.24
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_HASKELL_HACKAGE:=shakespeare-${PKGVERSION_NOREV}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.yesodweb.com/book/shakespearean-templates
COMMENT=	Toolkit for making compile-time interpolated templates
LICENSE=	mit

DEPENDS+=	hs-aeson-[0-9]*:../../converters/hs-aeson
DEPENDS+=	hs-exceptions-[0-9]*:../../devel/hs-exceptions

USE_LANGUAGES=	# none

.include "../../mk/haskell.mk"
.include "../../textproc/hs-blaze-html/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
