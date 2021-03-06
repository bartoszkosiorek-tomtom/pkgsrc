$NetBSD: patch-src_dvdbackup.c,v 1.3 2020/04/07 09:15:19 rhialto Exp $

Patch taken from FreeBSD ports.
FreeBSD PR:	https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=245228
Submitted by:	felix@palmen-it.de

--- src/dvdbackup.c.orig	2012-06-24 01:10:29 UTC
+++ src/dvdbackup.c
@@ -1132,7 +1132,7 @@ static int DVDCopyIfoBup(dvd_reader_t* dvd, title_set_
 	int size;
 
 	/* DVD handler */
-	ifo_handle_t* ifo_file = NULL;
+	dvd_file_t* ifo_file = NULL;
 
 
 	if (title_set_info->number_of_title_sets + 1 < title_set) {
@@ -1181,7 +1181,7 @@ static int DVDCopyIfoBup(dvd_reader_t* dvd, title_set_
 	if ((streamout_ifo = open(targetname_ifo, O_WRONLY | O_CREAT | O_TRUNC, 0666)) == -1) {
 		fprintf(stderr, _("Error creating %s\n"), targetname_ifo);
 		perror(PACKAGE);
-		ifoClose(ifo_file);
+		DVDCloseFile(ifo_file);
 		free(buffer);
 		close(streamout_ifo);
 		close(streamout_bup);
@@ -1191,7 +1191,7 @@ static int DVDCopyIfoBup(dvd_reader_t* dvd, title_set_
 	if ((streamout_bup = open(targetname_bup, O_WRONLY | O_CREAT | O_TRUNC, 0666)) == -1) {
 		fprintf(stderr, _("Error creating %s\n"), targetname_bup);
 		perror(PACKAGE);
-		ifoClose(ifo_file);
+		DVDCloseFile(ifo_file);
 		free(buffer);
 		close(streamout_ifo);
 		close(streamout_bup);
@@ -1200,31 +1200,31 @@ static int DVDCopyIfoBup(dvd_reader_t* dvd, title_set_
 
 	/* Copy VIDEO_TS.IFO, since it's a small file try to copy it in one shot */
 
-	if ((ifo_file = ifoOpen(dvd, title_set))== 0) {
+	if ((ifo_file = DVDOpenFile(dvd, title_set, DVD_READ_INFO_FILE))== 0) {
 		fprintf(stderr, _("Failed opening IFO for title set %d\n"), title_set);
-		ifoClose(ifo_file);
+		DVDCloseFile(ifo_file);
 		free(buffer);
 		close(streamout_ifo);
 		close(streamout_bup);
 		return 1;
 	}
 
-	size = DVDFileSize(ifo_file->file) * DVD_VIDEO_LB_LEN;
+	size = DVDFileSize(ifo_file) * DVD_VIDEO_LB_LEN;
 
 	if ((buffer = (unsigned char *)malloc(size * sizeof(unsigned char))) == NULL) {
 		perror(PACKAGE);
-		ifoClose(ifo_file);
+		DVDCloseFile(ifo_file);
 		free(buffer);
 		close(streamout_ifo);
 		close(streamout_bup);
 		return 1;
 	}
 
-	DVDFileSeek(ifo_file->file, 0);
+	DVDFileSeek(ifo_file, 0);
 
-	if (DVDReadBytes(ifo_file->file,buffer,size) != size) {
+	if (DVDReadBytes(ifo_file,buffer,size) != size) {
 		fprintf(stderr, _("Error reading IFO for title set %d\n"), title_set);
-		ifoClose(ifo_file);
+		DVDCloseFile(ifo_file);
 		free(buffer);
 		close(streamout_ifo);
 		close(streamout_bup);
@@ -1234,7 +1234,7 @@ static int DVDCopyIfoBup(dvd_reader_t* dvd, title_set_
 
 	if (write(streamout_ifo,buffer,size) != size) {
 		fprintf(stderr, _("Error writing %s\n"),targetname_ifo);
-		ifoClose(ifo_file);
+		DVDCloseFile(ifo_file);
 		free(buffer);
 		close(streamout_ifo);
 		close(streamout_bup);
@@ -1243,7 +1243,7 @@ static int DVDCopyIfoBup(dvd_reader_t* dvd, title_set_
 
 	if (write(streamout_bup,buffer,size) != size) {
 		fprintf(stderr, _("Error writing %s\n"),targetname_bup);
-		ifoClose(ifo_file);
+		DVDCloseFile(ifo_file);
 		free(buffer);
 		close(streamout_ifo);
 		close(streamout_bup);
@@ -1546,7 +1546,6 @@ int DVDMirror(dvd_reader_t * _dvd, char * targetdir,ch
 
 	title_set_info = DVDGetFileSet(_dvd);
 	if (!title_set_info) {
-		DVDClose(_dvd);
 		return(1);
 	}
 
@@ -1573,7 +1572,6 @@ int DVDMirrorTitleSet(dvd_reader_t * _dvd, char * targ
 	title_set_info = DVDGetFileSet(_dvd);
 
 	if (!title_set_info) {
-		DVDClose(_dvd);
 		return(1);
 	}
 
