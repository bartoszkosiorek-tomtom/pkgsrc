# $NetBSD: Makefile,v 1.16 2020/04/28 09:45:26 wiz Exp $

DISTNAME=	osbf-lua-2.0.4
PKGREVISION=	6
CATEGORIES=	mail
MASTER_SITES=	http://luaforge.net/frs/download.php/2094/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://osbf-lua.luaforge.net/
COMMENT=	Lua C module for text classification
LICENSE=	gnu-gpl-v2

PREV_PKGPATH=	mail/lua-OSBF

USE_TOOLS+=		gmake

INSTALL_TARGET=	install install_spamfilter

LUA_VERSIONS_ACCEPTED=	52

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Fixing paths in config
SUBST_FILES.path=	config
SUBST_FILES.path+=	spamfilter/getopt.lua
SUBST_FILES.path+=	docs/index.html
SUBST_SED.path=		-e 's,/usr/local,${PREFIX},g'
SUBST_SED.path+=	-e 's,lib/lua/5.1,lib/lua/5.2,g'

REPLACE_LUA+=	spamfilter/cache_report.lua
REPLACE_LUA+=	spamfilter/classify.sample
REPLACE_LUA+=	spamfilter/create_databases.lua
REPLACE_LUA+=	spamfilter/database_status.lua
REPLACE_LUA+=	spamfilter/getopt.lua
REPLACE_LUA+=	spamfilter/random.lua
REPLACE_LUA+=	spamfilter/roc.lua
REPLACE_LUA+=	spamfilter/spamfilter.lua
REPLACE_LUA+=	spamfilter/spamfilter_commands.lua
REPLACE_LUA+=	spamfilter/toer.lua
REPLACE_LUA+=	spamfilter/train.sample

.include "../../lang/lua/application.mk"

.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
