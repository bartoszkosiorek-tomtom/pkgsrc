# $NetBSD: Makefile,v 1.4 2020/08/17 20:19:09 leot Exp $
#

DISTNAME=		cairo-gobject-${VERSION}
COMMENT=		Ruby binding of cairo-gobject
PKGREVISION=		1
CATEGORIES=		graphics gnome

MAINTAINER=		tsutsui@NetBSD.org

CONFLICTS+=		ruby-gnome2-cairo-gobject-[0-9]*
SUPERSEDES+=		ruby-gnome2-cairo-gobject-[0-9]*

DEPENDS+=		${RUBY_PKGPREFIX}-glib2>=${VERSION}:../../devel/ruby-glib2
DEPENDS+=		${RUBY_PKGPREFIX}-cairo>=1.16.2:../../graphics/ruby-cairo

.include "../../devel/ruby-glib2/buildlink3.mk"
.include "../../graphics/ruby-cairo/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
