# g++ 3.3 crashes through excessive memory usage when compiling bison output.
# Tweek the inline function size limit below as you see fit.
# Nick Bailey, Niall Moody. http://cmt.gla.ac.uk

AM_CXXFLAGS = -g -finline-limit=100
AM_YFLAGS = -d -y
AM_LDFLAGS = 
LIBS =

bin_PROGRAMS = taoparse

taoparse_SOURCES = taoparser.yy taoscanner.ll taoparserdefs.h

CLEANFILES = \
	taoscanner.cc \
	taoparser.cc \
	taoparser.h \
	y.tab.c \
	y.tab.h \
	*~

taoscanner.ll:
	taoparser.cc taoparser.yy taoparser.h

dist-hook:
	$(RM) -f $(distdir)/*.cc

