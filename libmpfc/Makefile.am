lib_LTLIBRARIES = libmpfc.la

libmpfchdrdir = $(includedir)/mpfc
libmpfchdr_HEADERS = ../mpfc-config.h ../src/types.h ../src/cfg.h \
					 ../src/pmng.h ../src/util.h ../src/song_info.h ../src/mystring.h \
					 ../src/logger.h ../src/plugin.h \
					 ../src/genp.h ../src/command.h ../src/main_types.h \
					 ../src/plp.h

libmpfc_la_SOURCES = cfg.c plugin_mng.c util.c \
					 song_info.c string.c logger.c cfg_rcfile.c \
					 plugin.c plugin_general.c plugin_plist.c command.c \
					 $(libmpfchdr_HEADERS)
libmpfc_la_LIBADD = @COMMON_LIBS@ @RESOLV_LIBS@ @DL_LIBS@
libmpfc_la_LDFLAGS = -version-info 2:0
AM_CPPFLAGS = -I$(top_srcdir)/src -I$(top_srcdir)/libmpfcwnd @GSTREAMER_CFLAGS@ @TAGLIB_CFLAGS@ @CURSES_CFLAGS@
localedir = $(datadir)/locale
