# $NetBSD: Makefile,v 1.12 2020/05/10 04:32:03 markd Exp $

DISTNAME=	hyphen-polish
PKGNAME=	tex-${DISTNAME}-3.0a.2019.51186
PKGREVISION=	1
TEXLIVE_REV=	51186

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation for Polish
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	polish loadhyph-pl.tex
TEX_HYPHEN_DEF+=	\\addlanguage{polish}{loadhyph-pl.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['polish']={ \
			  loader='loadhyph-pl.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-pl.pat.txt', \
			  hyphenation='hyph-pl.hyp.txt', \
			},

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
