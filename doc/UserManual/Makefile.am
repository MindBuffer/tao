SUBDIRS = html
HTMLARNAME = tao-${TAO_VERSION}-usermanual-html
PSFILENAME = tao-${TAO_VERSION}-usermanual.ps
GZIPENV = --best

EXTRA_DIST = \
	UserManual.tex \
	closing_comments.tex \
	conceptual_overview.tex \
	getting_started.tex \
	installation.tex \
	introduction.tex \
	script_language.tex \
	script_reference.tex \
	tutorial.tex \
	user_interface.tex \
	cells.eps \
	circle_example.eps \
	circle_waves.eps \
	compound_example.eps \
	instrument_coord_system.eps \
	instrvis.eps \
	joining.eps \
	new.eps \
	xandyfreqs.eps

CLEANFILES = \
	UserManual.bbl \
	UserManual.ilg \
	UserManual.blg \
	UserManual.dvi \
	UserManual.ps \
	UserManual.log \
	UserManual.idx \
	UserManual.ind \
	UserManual.toc \
	UserManual.lof \
	UserManual.aux \
	${HTMLARNAME}.tgz \
	${PSFILENAME}.gz

MAINTAINERCLEANFILES = introduction.tex

html:	html/UserManual.html

ps:	UserManual.ps

html-archive: html/UserManual.html
	mkdir /tmp/${HTMLARNAME}
	cp html/*.html html/*.gif /tmp/${HTMLARNAME}
	cd /tmp ; ${TAR} czvf ${HTMLARNAME}.tar.gz ${HTMLARNAME}
	mv /tmp/${HTMLARNAME}.tar.gz .
	rm -rf /tmp/${HTMLARNAME}

psgzip: UserManual.ps
	gzip ${GZIP_ENV} UserManual.ps
	mv UserManual.ps.gz ${PSFILENAME}.gz

html/UserManual.html: ${EXTRA_DIST}
	hyperlatex UserManual

UserManual.dvi: ${EXTRA_DIST}
	latex UserManual
	latex UserManual
	makeindex UserManual
	latex UserManual

UserManual.ps: UserManual.dvi
	allneeded UserManual.dvi
	dvips -f <UserManual.dvi >UserManual.ps

downloads: psgzip html-archive

.PHONY: html ps html-archive psgzip