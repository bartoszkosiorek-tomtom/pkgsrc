# $NetBSD: Makefile,v 1.4 2020/01/18 23:30:58 rillig Exp $
TRYTON_MODULE_NAME=	trytond_sale_promotion
.include "../../devel/py-trytond/Makefile.common"
CATEGORIES=	finance python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tryton.org/
COMMENT=	Sale promotion module of the Tryton application platform
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-simpleeval-[0-9]*:../../math/py-simpleeval
DEPENDS+=	${PYPKGPREFIX}-trytond-company>=${TRYTON_BASEVER}:../../misc/py-trytond-company
DEPENDS+=	${PYPKGPREFIX}-trytond-product>=${TRYTON_BASEVER}:../../misc/py-trytond-product
DEPENDS+=	${PYPKGPREFIX}-trytond-product-price-list>=${TRYTON_BASEVER}:../../finance/py-trytond-product-price-list
DEPENDS+=	${PYPKGPREFIX}-trytond-sale>=${TRYTON_BASEVER}:../../finance/py-trytond-sale
DEPENDS+=	${PYPKGPREFIX}-trytond-sale-price-list>=${TRYTON_BASEVER}:../../finance/py-trytond-sale-price-list
DEPENDS+=	${PYPKGPREFIX}-trytond>=${TRYTON_BASEVER}:../../devel/py-trytond

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
