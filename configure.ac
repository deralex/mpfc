AC_INIT(src/main.c)
AM_INIT_AUTOMAKE(mpfc, 1.3.8-svn)
AC_PROG_CC
AC_C_BIGENDIAN
AC_PROG_LIBTOOL

AM_CONFIG_HEADER(mpfc-config.h)
AM_GNU_GETTEXT
AM_GNU_GETTEXT_VERSION(0.16.1)

# Set up common libraries
#COMMON_LIBS="-ldmalloc"
COMMON_LIBS=""
AC_SUBST(COMMON_LIBS)

# Check for ncurses
LIBS_save=$LIBS
AC_CHECK_HEADERS([curses.h],,[AC_MSG_ERROR(*** Can't find curses.h ***)])
AC_CHECK_LIB(ncursesw, waddch,,[AC_MSG_ERROR(*** Can't find ncurses library ***)])
CURSES_LIBS="-lncursesw"
AC_SUBST(CURSES_LIBS)
LIBS=$LIBS_save

# Check for pthread
LIBS_save=$LIBS
AC_CHECK_HEADERS([pthread.h],,[AC_MSG_ERROR(*** Can't find pthread.h ***)])
AC_CHECK_LIB(pthread, pthread_create,,[AC_MSG_ERROR(*** Can't find posix threads library ***)])
PTHREAD_LIBS="-lpthread"
AC_SUBST(PTHREAD_LIBS)
LIBS=$LIBS_save

# Check for libdl
LIBS_save=$LIBS
AC_CHECK_HEADERS([dlfcn.h],,[AC_MSG_ERROR(*** Can't find dlfcn.h ***)])
AC_CHECK_LIB(dl, dlopen,,[AC_MSG_ERROR(*** Can't find libdl ***)])
DL_LIBS="-ldl"
AC_SUBST(DL_LIBS)
LIBS=$LIBS_save

# Check for gpm library
AC_ARG_ENABLE(gpm, 
[	--disable-gpm		Disable gpm support [default=enabled]],,
		enable_gpm="yes")
if test "x$enable_gpm" = xyes; then
	LIBS_save=$LIBS
	AC_CHECK_HEADERS([gpm.h],,[AC_MSG_ERROR(*** Can't find gpm.h ***)])
	AC_CHECK_LIB(gpm, Gpm_Open,,[AC_MSG_ERROR(*** Can't find gpm library ***)])
	GPM_LIBS="-lgpm"
	AC_SUBST(GPM_LIBS)
	LIBS=$LIBS_save
else
	AC_MSG_RESULT([*** gpm support disabled per user request ***])
fi

# Check for soundcard header 
AC_CHECK_HEADERS([sys/soundcard.h],, [AC_MSG_ERROR(*** Can't find sys/soundcard.h ***)])

# Check for resolver library
LIBS_save=$LIBS
AC_CHECK_HEADERS([netdb.h],,[AC_MSG_ERROR(*** Can't find libresolv header ***)])
AC_CHECK_LIB(resolv, gethostbyname,,[AC_MSG_ERROR(*** Can't find libresolv ***)])
RESOLV_LIBS="-lresolv"
AC_SUBST(RESOLV_LIBS)
LIBS=$LIBS_save

# Stuff for mp3 plugin
AC_ARG_ENABLE(mp3, 
[	--disable-mp3		Disable mp3 input plugin [default=enabled]],,
		enable_mp3="yes")
if test "x$enable_mp3" = xyes; then
	# Check for math lib
	LIBS_save=$LIBS
	AC_CHECK_HEADERS([math.h],,[AC_MSG_ERROR(*** Can't find math header ***)])
	AC_CHECK_LIB(m, pow,,[AC_MSG_ERROR(*** Can't find libm ***)])
	MATH_LIBS="-lm"
	AC_SUBST(MATH_LIBS)
	LIBS=$LIBS_save

	# Check for libmad
	LIBS_save=$LIBS
	AC_CHECK_HEADERS([mad.h],,[AC_MSG_ERROR(*** Can't find libmad header ***)])
	AC_CHECK_LIB(m, pow,,[AC_MSG_ERROR(*** Can't find libmad ***)])
	MAD_LIBS="-lmad"
	AC_SUBST(MAD_LIBS)
	LIBS=$LIBS_save
else
	AC_MSG_RESULT([*** mp3 plugin disabled per user request ***])
fi

# Stuff for audiocd plugin
AC_ARG_ENABLE(audiocd, 
[	--disable-audiocd	Disable audiocd input plugin [default=enabled]],,
		enable_audiocd="yes")
if test "x$enable_audiocd" = xyes; then
	# Check for cdrom includes
	AC_CHECK_HEADERS([linux/cdrom.h],, [AC_MSG_ERROR(*** Can't find linux/cdrom.h ***)])
else
	AC_MSG_RESULT([*** audiocd plugin disabled per user request ***])
fi

# Stuff for ogg plugin
AC_ARG_ENABLE(ogg, 
[	--disable-ogg		Disable ogg input plugin [default=enabled]],,
		enable_ogg="yes")
if test "x$enable_ogg" = xyes; then
	# Check for libvorbis
	LIBS_save=$LIBS
	AC_CHECK_LIB(vorbis, vorbis_dsp_clear,,[AC_MSG_ERROR(*** Can't find libvorbis ***)])
	AC_CHECK_LIB(vorbisfile, ov_open,,[AC_MSG_ERROR(*** Can't find libvorbisfile ***)])
	AC_CHECK_LIB(ogg, ogg_stream_init,,[AC_MSG_ERROR(*** Can't find libogg ***)])
	AC_CHECK_HEADERS([vorbis/codec.h vorbis/vorbisfile.h ogg/ogg.h],,
					 [AC_MSG_ERROR(*** Can't find ogg headers ***)])
	OGG_LIBS="-lvorbis -lvorbisfile -logg"
	AC_SUBST(OGG_LIBS)
	LIBS=$LIBS_save
else
	AC_MSG_RESULT([*** ogg plugin disabled per user request ***])
fi

# Stuff for alsa plugin
AC_ARG_ENABLE(alsa, 
[	--disable-alsa		Disable alsa input plugin [default=enabled]],,
		enable_alsa="yes")
if test "x$enable_alsa" = xyes; then
	# Check for asound lib
	LIBS_save=$LIBS
	AC_CHECK_HEADERS([alsa/asoundlib.h],, [AC_MSG_ERROR(*** Can't find alsa/asoundlib.h ***)])
	AC_CHECK_LIB(asound, snd_pcm_open,,[AC_MSG_ERROR(*** Can't find libasound ***)])
	ASOUND_LIBS="-lasound"
	AC_SUBST(ASOUND_LIBS)
	LIBS=$LIBS_save
else
	AC_MSG_RESULT([*** alsa plugin disabled per user request ***])
fi

# Set enabling stuff for other plugins
AC_ARG_ENABLE(wav, 
[	--disable-wav		Disable wav input plugin [default=enabled]],,
		enable_wav="yes")
AC_ARG_ENABLE(disk_writer, 
[	--disable-disk_writer	Disable disk_writer output plugin 
 	[default=enabled]],, enable_disk_writer="yes")
AC_ARG_ENABLE(oss, 
[	--disable-oss		Disable oss output plugin [default=enabled]],,
		enable_oss="yes")

# Choose input plugins
ALL_INPUT_PLUGINS="audiocd mp3 ogg wav"
for plugin in $ALL_INPUT_PLUGINS; do
	name="\$enable_$plugin"
	value=`eval echo $name`
	SUMMARY_MSG="No"
	if test "x${value}" = xyes; then
		INPUT_PLUGINS="$INPUT_PLUGINS $plugin"
		SUMMARY_MSG="Yes"
	fi
	INPUT_SUMMARY="$INPUT_SUMMARY\n$plugin: $SUMMARY_MSG"
done

# Choose output plugins
ALL_OUTPUT_PLUGINS="alsa disk_writer oss"
for plugin in $ALL_OUTPUT_PLUGINS; do
	name="\$enable_$plugin"
	value=`eval echo $name`
	SUMMARY_MSG="No"
	if test "x${value}" = xyes; then
		OUTPUT_PLUGINS="$OUTPUT_PLUGINS $plugin"
		SUMMARY_MSG="Yes"
	fi
	OUTPUT_SUMMARY="$OUTPUT_SUMMARY\n$plugin: $SUMMARY_MSG"
done

# Choose effect plugins
ALL_EFFECT_PLUGINS=""
for plugin in $ALL_EFFECT_PLUGINS; do
	name="\$enable_effect_$plugin"
	value=`eval echo $name`
	SUMMARY_MSG="No"
	if test "x${value}" = xyes; then
		EFFECT_PLUGINS="$EFFECT_PLUGINS $plugin"
		SUMMARY_MSG="Yes"
	fi
	EFFECT_SUMMARY="$EFFECT_SUMMARY\n$plugin: $SUMMARY_MSG"
done

# Choose charset plugins
ALL_CHARSET_PLUGINS=""
for plugin in $ALL_CHARSET_PLUGINS; do
	name="\$enable_charset_$plugin"
	value=`eval echo $name`
	SUMMARY_MSG="No"
	if test "x${value}" = xyes; then
		CHARSET_PLUGINS="$CHARSET_PLUGINS $plugin"
		SUMMARY_MSG="Yes"
	fi
	CHARSET_SUMMARY="$CHARSET_SUMMARY\n$plugin: $SUMMARY_MSG"
done

# Choose general plugins
ALL_GENERAL_PLUGINS=""
for plugin in $ALL_GENERAL_PLUGINS; do
	name="\$enable_general_$plugin"
	value=`eval echo $name`
	SUMMARY_MSG="No"
	if test "x${value}" = xyes; then
		GENERAL_PLUGINS="$GENERAL_PLUGINS $plugin"
		SUMMARY_MSG="Yes"
	fi
	GENERAL_SUMMARY="$GENERAL_SUMMARY\n$plugin: $SUMMARY_MSG"
done

AC_SUBST(GENERAL_PLUGINS)
AC_SUBST(CHARSET_PLUGINS)
AC_SUBST(EFFECT_PLUGINS)
AC_SUBST(INPUT_PLUGINS)
AC_SUBST(OUTPUT_PLUGINS)

AC_OUTPUT(Makefile \
		  doc/Makefile \
		  intl/Makefile  \
		  libmpfc/Makefile \
		  libmpfcwnd/Makefile \
		  po/Makefile.in  \
		  src/Makefile \
		  plugins/Makefile \
		  plugins/charset/Makefile \
		  plugins/effect/Makefile \
		  plugins/general/Makefile \
		  plugins/input/Makefile \
		  plugins/input/audiocd/Makefile \
		  plugins/input/mp3/Makefile \
		  plugins/input/ogg/Makefile \
		  plugins/input/wav/Makefile \
		  plugins/output/Makefile \
		  plugins/output/alsa/Makefile \
		  plugins/output/disk_writer/Makefile \
		  plugins/output/oss/Makefile \
		  po/Makefile \
		  mpfc.pc)

# Configure rcfiles
./build_rcfile.pl "$OUTPUT_PLUGINS" "local" > src/.mpfcrc
./build_rcfile.pl "$OUTPUT_PLUGINS" "global" > mpfcrc

# Print plugins summary
echo -e "\n****** Plugins summary ******\n"
echo -e "Input plugins:$INPUT_SUMMARY\n"
echo -e "Output plugins:$OUTPUT_SUMMARY\n"
echo -e "Effect plugins:$EFFECT_SUMMARY\n"
echo -e "Charset plugins:$CHARSET_SUMMARY\n"
echo -e "General plugins:$GENERAL_SUMMARY\n"