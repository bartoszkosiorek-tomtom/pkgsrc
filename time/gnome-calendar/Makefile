# $NetBSD: Makefile,v 1.3 2020/11/17 15:31:51 nia Exp $

DISTNAME=	gnome-calendar-3.38.1
MASTER_SITES=	${MASTER_SITE_GNOME:=/sources/${PKGBASE}/${PKGVERSION_NOREV:R}/}
CATEGORIES=	time gnome
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Apps/Calendar/
COMMENT=	Calendar application for GNOME
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	gdbus-codegen-[0-9]*:../../devel/gdbus-codegen

USE_TOOLS+=	pkg-config msgfmt xgettext

.include "../../mk/bsd.prefs.mk"

# msgfmt: unknown option -- desktop
.if ${OPSYS} == "NetBSD"
TOOLS_PLATFORM.msgfmt=
.endif

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/libdazzle/buildlink3.mk"
.include "../../devel/libgweather/buildlink3.mk"
.include "../../devel/libhandy/buildlink3.mk"
.include "../../geography/geoclue/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../time/libical/buildlink3.mk"
.include "../../net/gnome-online-accounts/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
