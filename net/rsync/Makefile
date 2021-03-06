# $NetBSD: Makefile,v 1.115 2020/08/07 08:33:37 adam Exp $

DISTNAME=	rsync-3.2.3
CATEGORIES=	net
MASTER_SITES=	http://rsync.samba.org/ftp/rsync/
MASTER_SITES+=	http://rsync.samba.org/ftp/rsync/old-versions/
MASTER_SITES+=	ftp://ftp.fu-berlin.de/unix/network/rsync/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rsync.samba.org/
COMMENT=	Network file distribution/synchronisation utility
LICENSE=	gnu-gpl-v3

USE_TOOLS+=		bash:run
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-rsyncd-conf=${PKG_SYSCONFDIR}/rsyncd.conf
PKG_SYSCONFSUBDIR=	rsync
TEST_TARGET=		test

REPLACE_BASH=		rsync-ssl

RCD_SCRIPTS=		rsyncd
RCD_SCRIPT_SRC.rsyncd=	files/rsyncd.sh
SMF_NAME=		rsyncd

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	rsync.1 rsyncd.conf.5
SUBST_SED.paths=	-e 's|/etc/rsyncd|${PKG_SYSCONFDIR}/rsyncd|g'
SUBST_SED.paths+=	-e 's|/usr/bin/rsync|${PREFIX}/bin/rsync|g'

.include "../../archivers/lz4/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/xxhash/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
