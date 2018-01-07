# $NetBSD: buildlink3.mk,v 1.2 2018/01/07 13:04:17 rillig Exp $

BUILDLINK_TREE+=	hackrf

.if !defined(HACKRF_BUILDLINK3_MK)
HACKRF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hackrf+=	hackrf>=0.1
BUILDLINK_ABI_DEPENDS.hackrf+=	hackrf>=0.1
BUILDLINK_PKGSRCDIR.hackrf?=	../../ham/hackrf
.endif # HACKRF_BUILDLINK3_MK

BUILDLINK_TREE+=	-hackrf
