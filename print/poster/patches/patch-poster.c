$NetBSD: patch-poster.c,v 1.2 2015/12/29 04:04:31 dholland Exp $

--- poster.c.old	2006-02-22 13:27:39.000000000 +0100
+++ poster.c	2012-11-17 01:30:45.303051611 +0100
@@ -856,21 +856,13 @@
 	int row, col, page;
 
 	printprolog();
-	for ( page = 0; page < number_pages; page++ )
-	{
-		printf( "/print_content_of_complete_page_%d\n", page);
-		printf( "{\n");
-		printfile (page);
-		printf( "} bind def\n\n");
-	
 		if ( pages == NULL )
-		{
+		for ( page = 0; page < number_pages; page++ )
 			for (row = 1; row <= nrows; row++)
 				for (col = 1; col <= ncols; col++)
 					tile( row, col, page);
-		}
 		else
-		{
+		for ( page = 0; page < number_pages; page++ )
 			for ( row = 0; row < pages_length; row++ )
 			{
 				int p = pages[ row ]-1;
@@ -878,8 +870,6 @@
 					fprintf( stderr, "Warning: page index out of range: %d\n", p+1 );
 				tile( p/ncols+1, p%ncols+1, page );
 			}
-		}
-	}
 	printf ("%%%%EOF\n");
 
 	if (tail_cntl_D)
@@ -1027,7 +1017,7 @@
 	printf ("\n%%%%Page: (%d,%d) %d\n", pagetoprint+1, ((row-1)*ncols+col), page);
 	printf ("%d %d tileprolog\n", row, col);
 	printf ("%%%%BeginDocument: %s\n", infile);
-	printf( "print_content_of_complete_page_%d\n", pagetoprint);
+	printfile (pagetoprint);	
 	printf ("%%%%EndDocument\n");
 	printf ("tileepilog\n");
 
