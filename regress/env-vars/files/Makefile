# $NetBSD: Makefile,v 1.2 2018/11/09 06:59:20 rillig Exp $

all install:
	@set -eu; \
	env | sed -n -e 's/^\([^=]*\)_set=yes$$/\1/p' | LC_ALL=C sort \
	> "$$REGRESS_TMPDIR/make-${.TARGET}.vars"
