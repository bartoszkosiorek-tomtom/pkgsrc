# $NetBSD: Makefile,v 1.24 2019/11/04 21:43:39 rillig Exp $
#

DISTNAME=	ocaml-text-0.8
PKGREVISION=	9
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=vbmithr/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/vbmithr/ocaml-text
COMMENT=	OCaml Unicode library
LICENSE=	modified-bsd

HAS_CONFIGURE=		yes

#SUBST_CLASSES+=	destdir
#SUBST_STAGE.destdir=	post-configure
#SUBST_MESSAGE.destdir=	Changing install location to DESTDIR
#SUBST_FILES.destdir=	setup.ml
#SUBST_SED.destdir=	-e 's,"install" :: findlib_name,"install" :: "-destdir ${DESTDIR}${PREFIX}/lib/ocaml/site-lib" :: "-ldconf /dev/null" :: findlib_name,'

OCAML_USE_OASIS=	yes

.include "../../mk/ocaml.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
