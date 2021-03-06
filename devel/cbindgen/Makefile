# $NetBSD: Makefile,v 1.23 2020/10/11 13:04:35 ryoon Exp $

DISTNAME=	cbindgen-0.15.0
CATEGORIES=	devel
EXTRACT_SUFX=	.crate

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/eqrion/cbindgen/releases
COMMENT=	Generating C bindings from Rust code
LICENSE=	mpl-2.0

CARGO_CRATE_DEPENDS+=	ansi_term-0.11.0
CARGO_CRATE_DEPENDS+=	atty-0.2.14
CARGO_CRATE_DEPENDS+=	autocfg-1.0.1
CARGO_CRATE_DEPENDS+=	bitflags-1.2.1
CARGO_CRATE_DEPENDS+=	cfg-if-0.1.10
CARGO_CRATE_DEPENDS+=	clap-2.33.3
CARGO_CRATE_DEPENDS+=	getrandom-0.1.15
CARGO_CRATE_DEPENDS+=	hashbrown-0.9.1
CARGO_CRATE_DEPENDS+=	heck-0.3.1
CARGO_CRATE_DEPENDS+=	hermit-abi-0.1.16
CARGO_CRATE_DEPENDS+=	indexmap-1.6.0
CARGO_CRATE_DEPENDS+=	itoa-0.4.6
CARGO_CRATE_DEPENDS+=	libc-0.2.77
CARGO_CRATE_DEPENDS+=	log-0.4.11
CARGO_CRATE_DEPENDS+=	ppv-lite86-0.2.9
CARGO_CRATE_DEPENDS+=	proc-macro2-1.0.21
CARGO_CRATE_DEPENDS+=	quote-1.0.7
CARGO_CRATE_DEPENDS+=	rand-0.7.3
CARGO_CRATE_DEPENDS+=	rand_chacha-0.2.2
CARGO_CRATE_DEPENDS+=	rand_core-0.5.1
CARGO_CRATE_DEPENDS+=	rand_hc-0.2.0
CARGO_CRATE_DEPENDS+=	redox_syscall-0.1.57
CARGO_CRATE_DEPENDS+=	remove_dir_all-0.5.3
CARGO_CRATE_DEPENDS+=	ryu-1.0.5
CARGO_CRATE_DEPENDS+=	serde-1.0.116
CARGO_CRATE_DEPENDS+=	serde_derive-1.0.116
CARGO_CRATE_DEPENDS+=	serde_json-1.0.57
CARGO_CRATE_DEPENDS+=	strsim-0.8.0
CARGO_CRATE_DEPENDS+=	syn-1.0.41
CARGO_CRATE_DEPENDS+=	tempfile-3.1.0
CARGO_CRATE_DEPENDS+=	textwrap-0.11.0
CARGO_CRATE_DEPENDS+=	toml-0.5.6
CARGO_CRATE_DEPENDS+=	unicode-segmentation-1.6.0
CARGO_CRATE_DEPENDS+=	unicode-width-0.1.8
CARGO_CRATE_DEPENDS+=	unicode-xid-0.2.1
CARGO_CRATE_DEPENDS+=	vec_map-0.8.2
CARGO_CRATE_DEPENDS+=	wasi-0.9.0+wasi-snapshot-preview1
CARGO_CRATE_DEPENDS+=	winapi-0.3.9
CARGO_CRATE_DEPENDS+=	winapi-i686-pc-windows-gnu-0.4.0
CARGO_CRATE_DEPENDS+=	winapi-x86_64-pc-windows-gnu-0.4.0

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/cbindgen ${DESTDIR}${PREFIX}/bin

RUST_RUNTIME=	yes
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
