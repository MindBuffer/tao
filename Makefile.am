## Process this file with automake to produce Makefile.in

SRC_SUBDIRS = libtao include taoparse tao2aiff tao2wav
SUBDIRS = $(SRC_SUBDIRS) user-scripts doc examples

EXTRA_DIST = TODO \
	README.FIRST \
	diagnose-lib \
	CygwinPackageRequirements.txt

docs:
	cd doc && $(MAKE) docs

alldocs:
	cd doc && $(MAKE) alldocs
