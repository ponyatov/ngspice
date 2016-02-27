## Process this file with automake to produce Makefile.in

SUBDIRS = misc include/ngspice
DIST_SUBDIRS = misc include/ngspice

bin_PROGRAMS =  ngspice

EXTRA_DIST = ngspice.txt

DYNAMIC_DEVICELIBS =

## Build ngspice first:

ngspice_SOURCES = \
	main.c \
	conf.c \
	conf.h \
	ngspice.c

ngspice_CPPFLAGS = $(AM_CPPFLAGS) -DSIMULATOR

if WINGUI
ngspice_SOURCES += winmain.c
endif



ngspice_LDADD = \
	misc/libmisc.la



## create spinit at compile time, see
##   (info "(autoconf) Installation Directory Variables")

edit = sed \
	-e 's|@XSPICEINIT[@]|$(XSPICEINIT)|g' \
	-e 's|@pkglibdir[@]|$(pkglibdir)|g'

spinit tclspinit : Makefile
	rm -f $@ $@.tmp
	srcdir=''; \
	  test -f ./$@.in || srcdir=$(srcdir)/; \
	  $(edit) $${srcdir}$@.in >$@.tmp
	mv $@.tmp $@

spinit: $(srcdir)/spinit.in
tclspinit: $(srcdir)/tclspinit.in


## General Includes and libraries:

AM_CPPFLAGS = @AM_CPPFLAGS@ -I$(top_srcdir)/src/include -I$(top_srcdir)/src/spicelib/devices @X_CFLAGS@

AM_CFLAGS = -static

LIBS = @LIBS@ @X_LIBS@ @X_PRE_LIBS@ @X_EXTRA_LIBS@

if WINGUI
LIBS += -lpsapi
endif

CLEANFILES = ngspice.idx spinit tclspinit pkgIndex.tcl

MAINTAINERCLEANFILES = Makefile.in


EXTRA_DIST += spice.def
