# $NetBSD: Makefile,v 1.16 2020/10/02 14:20:34 khorben Exp $

.include "../../lang/llvm/version.mk"

DISTNAME=	compiler-rt-${LLVM_VERSION}.src
PKGNAME=	${DISTNAME:S/.src//}
PKGREVISION=	1
CATEGORIES=	lang devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://compiler-rt.llvm.org/
COMMENT=	LLVM runtime libraries
LICENSE=	apache-2.0

NOT_FOR_PLATFORM=	NetBSD-[0-7].*-*

USE_CMAKE=	yes
USE_LANGUAGES=	c99 c++11
USE_TOOLS+=	ggrep
GCC_REQD+=	4.8
SSP_SUPPORTED=	no

CONFIGURE_DIRS=	${WRKDIR}/build
CMAKE_ARG_PATH=	${WRKSRC}

OS_DIR=		${OPSYS:tl}

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=${CC:Q}
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=${CXX:Q}
CMAKE_ARGS+=	-DCOMPILER_RT_TEST_COMPILER=${PKG_CC:Q}
CMAKE_ARGS+=	-DCOMPILER_RT_OS_DIR:STRING=${OS_DIR}
CMAKE_ARGS+=	-DCOMPILER_RT_INSTALL_PATH:STRING=lib/clang/${PKGVERSION_NOREV}
CMAKE_ARGS+=	-DLLVM_CONFIG_PATH=${LLVM_CONFIG_PATH:Q}
CMAKE_ARGS+=	-DCOMPILER_RT_ENABLE_IOS=OFF

PLIST_SUBST+=	COMPILER_RT_OS_DIR=${OS_DIR}
PLIST_VARS+=	asan

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "SunOS"
PLIST.asan=	yes
.endif

TEST_TARGET=	check-compiler-rt

PYTHON_FOR_BUILD_ONLY=	yes

post-extract:
	${MKDIR} ${WRKDIR}/build

post-install:
	cd ${DESTDIR}${PREFIX} && \
	${FIND} lib/clang/${PKGVERSION_NOREV} -type f -name '*.dylib' \
		-exec install_name_tool -id ${PREFIX}/{} {} \;

.include "../../devel/googletest/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
