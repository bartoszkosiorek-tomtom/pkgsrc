# $NetBSD: Makefile,v 1.30 2020/11/13 19:26:12 bsiegert Exp $

DISTNAME=	purell-1.1.0
PKGNAME=	go-${DISTNAME}
PKGREVISION=	21
MASTER_SITES=	${MASTER_SITE_GITHUB:=PuerkitoBio/}
CATEGORIES=	devel
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PuerkitoBio/purell
COMMENT=	Purell is a tiny Go library to normalize URLs
LICENSE=	modified-bsd

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/PuerkitoBio/purell

.include "../../net/go-net/buildlink3.mk"
.include "../../www/go-urlesc/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
