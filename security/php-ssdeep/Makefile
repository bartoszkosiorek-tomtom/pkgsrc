# $NetBSD: Makefile,v 1.6 2020/01/18 23:35:11 rillig Exp $
#

MODNAME=		ssdeep
PECL_VERSION=		1.0.4
CATEGORIES+=		security

MAINTAINER=		khorben@defora.org
HOMEPAGE=		https://treffynnon.github.io/php_ssdeep/
COMMENT=		PHP extension for ssdeep
LICENSE=		artistic

PHP_VERSIONS_ACCEPTED=	56

CONFIGURE_ARGS+=	--with-ssdeep=${PREFIX}

CONFLICTS=		php-ssdeep-[0-9]*

.include "../../lang/php/ext.mk"
.include "../../security/ssdeep/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
