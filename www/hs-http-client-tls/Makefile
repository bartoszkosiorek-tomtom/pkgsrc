# $NetBSD: Makefile,v 1.1 2020/01/17 15:17:55 pho Exp $

DISTNAME=	http-client-tls-0.3.5.3
CATEGORIES=	www security

MAINTAINER=	pho@cielonegro.org
COMMENT=	TLS backend for Haskell http-client library
LICENSE=	mit

.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../net/hs-connection/buildlink3.mk"
.include "../../security/hs-cryptonite/buildlink3.mk"
.include "../../devel/hs-data-default-class/buildlink3.mk"
.include "../../devel/hs-exceptions/buildlink3.mk"
.include "../../www/hs-http-client/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../devel/hs-memory/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.include "../../security/hs-tls/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
