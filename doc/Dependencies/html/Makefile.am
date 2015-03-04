HTMLFILES = \
	Dependencies.html \
	Dependencies_1.html \
	Dependencies_2.html \
	Dependencies_3.html \
	Dependencies_4.html \
	Dependencies_5.html \
	Dependencies_6.html \
	Dependencies_7.html


EXTRA_DIST = ${HTMLFILES} \
	back.gif \
	bg.gif \
	forward.gif \
	trans1x1.gif \
	up.gif

MAINTAINERCLEANFILES = ${HTMLFILES}

Dependencies.html: ../Dependencies.tex
	cd .. && $(MAKE) html
