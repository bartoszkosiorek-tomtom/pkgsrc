# $NetBSD: buildlink3.mk,v 1.1 2020/01/18 23:30:04 pho Exp $

BUILDLINK_TREE+=	hs-ed25519

.if !defined(HS_ED25519_BUILDLINK3_MK)
HS_ED25519_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ed25519+=	hs-ed25519>=0.0.5
BUILDLINK_ABI_DEPENDS.hs-ed25519+=	hs-ed25519>=0.0.5.0
BUILDLINK_PKGSRCDIR.hs-ed25519?=	../../security/hs-ed25519
.endif	# HS_ED25519_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ed25519
