# $NetBSD: buildlink3.mk,v 1.10 2018/01/07 13:04:34 rillig Exp $

BUILDLINK_TREE+=	kakasi

.if !defined(KAKASI_BUILDLINK3_MK)
KAKASI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kakasi+=	kakasi>=2.3.0
BUILDLINK_ABI_DEPENDS.kakasi+=	kakasi>=2.3.4nb4
BUILDLINK_PKGSRCDIR.kakasi?=	../../textproc/kakasi

pkgbase := kakasi
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.kakasi:Mutf8)
.include "../../converters/libiconv/buildlink3.mk"
.endif

.endif # KAKASI_BUILDLINK3_MK

BUILDLINK_TREE+=	-kakasi
