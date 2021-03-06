# Created by: Anton Yudin <toha@FreeBSD.org>
# $FreeBSD$

PORTNAME=	warmux
DISTVERSION=	11.04.1
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	http://download.gna.org/${PORTNAME}/ \
		http://download.gna.org/${PORTNAME}/archive/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Turn-based artillery game with free software mascots

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxml++-2.6.so:textproc/libxml++26 \
		libcurl.so:ftp/curl

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	cxx_present=yes
USES=		compiler dos2unix gmake pkgconfig tar:bzip2
USE_SDL=	sdl image mixer ttf gfx net
DOS2UNIX_GLOB=	fixed_class.h

# build ignores CXXFLAGS
CFLAGS+=	${CFLAGS_${CHOSEN_COMPILER_TYPE}}
CFLAGS_clang=	-Wno-c++11-narrowing
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:R}

OPTIONS_DEFINE=	FRIBIDI SERVER NLS DEBUG
OPTIONS_SUB=	yes

DEBUG_CONFIGURE_ENABLE=	debug logging

FRIBIDI_DESC=		Enable bi-directional unicode support
FRIBIDI_LIB_DEPENDS=	libfribidi.so:converters/fribidi
FRIBIDI_CONFIGURE_ENABLE=	fribidi

NLS_USES=		gettext localbase:ldflags
NLS_CONFIGURE_ENABLE=	nls

SERVER_DESC=		Enable dedicated server
SERVER_CONFIGURE_ENABLE=	servers

post-patch:
	${REINPLACE_CMD} -e "s,-Werror,," ${WRKSRC}/Makefile.in \
	${WRKSRC}/src/Makefile.in ${WRKSRC}/configure
	${REINPLACE_CMD} -e "s,warmux_files.desktop,," ${WRKSRC}/data/Makefile.in
	${FIND} -d ${WRKSRC}/data/ -name "*.*~" -delete

.include <bsd.port.mk>
