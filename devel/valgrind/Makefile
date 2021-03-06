# $NetBSD: Makefile,v 1.33 2020/10/08 03:30:58 mcf Exp $
#

DISTNAME=		valgrind-3.16.1
CATEGORIES=		devel
MASTER_SITES=		ftp://sourceware.org/pub/valgrind/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://valgrind.org/
COMMENT=		Debugging and profiling tools
LICENSE=		gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	valgrind.pc.in
GNU_CONFIGURE=		yes

ONLY_FOR_PLATFORM=	Darwin-*-i386 Darwin-*-x86_64 \
			Linux-*-x86_64 \
			Linux-*-i386   \
			Linux-*-arm*   \
			SunOS-*-i386 SunOS-*-x86_64

USE_TOOLS+=		gmake perl
USE_LANGUAGES=		c c++
TEST_TARGET=		regtest
SSP_SUPPORTED=		no

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH:C/arm.*/arm/} == "arm"
PLIST_SUBST+=		VGCONF_ARCH_PRI=arm
.endif

.if ${MACHINE_ARCH} == "i386"
PLIST_SUBST+=		VGCONF_ARCH_PRI=x86
.endif

.if ${MACHINE_ARCH} == "x86_64"
PLIST_SUBST+=		VGCONF_ARCH_PRI=amd64
#PLIST_SUBST+=		VGCONF_ARCH_SEC=x86
CONFIGURE_ARGS+=	--enable-only64bit
.endif

.include "../../mk/bsd.pkg.mk"
