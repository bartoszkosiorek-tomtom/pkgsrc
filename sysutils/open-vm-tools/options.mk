# $NetBSD: options.mk,v 1.7 2018/01/01 06:56:01 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.open-vm-tools
PKG_SUPPORTED_OPTIONS=	icu x11
PKG_SUGGESTED_OPTIONS=	icu x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	x11

.if !empty(PKG_OPTIONS:Micu)
.include "../../textproc/icu/buildlink3.mk"
.else
CONFIGURE_ARGS+=		--without-icu
.endif

.if !empty(PKG_OPTIONS:Mx11)
PLIST.x11=	yes
MESSAGE_SRC+=	MESSAGE.x11
.  include "../../graphics/gdk-pixbuf2-xlib/buildlink3.mk"
.  include "../../sysutils/desktop-file-utils/desktopdb.mk"
.  include "../../x11/gtkmm3/buildlink3.mk"
.  include "../../x11/libXtst/buildlink3.mk"
.else
CONFIGURE_ARGS+=		--without-x
.endif
