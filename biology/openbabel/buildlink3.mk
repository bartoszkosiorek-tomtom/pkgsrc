# $NetBSD: buildlink3.mk,v 1.8 2020/11/05 09:06:43 ryoon Exp $

BUILDLINK_TREE+=	openbabel

.if !defined(OPENBABEL_BUILDLINK3_MK)
OPENBABEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openbabel+=	openbabel>=3.0.0nb1
BUILDLINK_ABI_DEPENDS.openbabel?=	openbabel>=3.1.1nb3
BUILDLINK_PKGSRCDIR.openbabel?=		../../biology/openbabel

.include "../../graphics/cairo/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../math/eigen2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif	# OPENBABEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-openbabel
