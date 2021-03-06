# $NetBSD: buildlink3.mk,v 1.16 2020/08/31 18:06:29 wiz Exp $

BUILDLINK_TREE+=	gnome-mime-data

.if !defined(GNOME_MIME_DATA_BUILDLINK3_MK)
GNOME_MIME_DATA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnome-mime-data+=	gnome-mime-data>=2.4.0
BUILDLINK_ABI_DEPENDS.gnome-mime-data+=	gnome-mime-data>=2.18.0nb9
BUILDLINK_PKGSRCDIR.gnome-mime-data?=	../../databases/gnome-mime-data

# intltool-{extract,merge,update} are Perl scripts included in the sources
# of packages that use gnome-mime-data and are executed during build.
#
USE_TOOLS+=	perl

.include "../../devel/gettext-lib/buildlink3.mk"
.endif # GNOME_MIME_DATA_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnome-mime-data
