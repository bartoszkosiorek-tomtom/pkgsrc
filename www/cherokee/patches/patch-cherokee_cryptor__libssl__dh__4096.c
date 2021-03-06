$NetBSD: patch-cherokee_cryptor__libssl__dh__4096.c,v 1.1 2020/04/15 22:38:19 joerg Exp $

Use OpenSSL 1.1 interface.

--- cherokee/cryptor_libssl_dh_4096.c.orig	2020-04-13 20:07:50.092112602 +0000
+++ cherokee/cryptor_libssl_dh_4096.c
@@ -55,9 +55,10 @@ static DH *get_dh4096()
 	DH *dh;
 
 	if ((dh=DH_new()) == NULL) return(NULL);
-	dh->p=BN_bin2bn(dh4096_p,sizeof(dh4096_p),NULL);
-	dh->g=BN_bin2bn(dh4096_g,sizeof(dh4096_g),NULL);
-	if ((dh->p == NULL) || (dh->g == NULL))
+	BIGNUM *p = BN_bin2bn(dh4096_p,sizeof(dh4096_p),NULL);
+	BIGNUM *g = BN_bin2bn(dh4096_g,sizeof(dh4096_g),NULL);
+	DH_set0_pqg(dh, p, NULL, g);
+	if (p == NULL || g == NULL)
 		{ DH_free(dh); return(NULL); }
 	return(dh);
 	}
