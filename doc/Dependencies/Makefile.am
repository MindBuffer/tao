SUBDIRS = html
HTMLARNAME = tao-${TAO_VERSION}-dependencies-html
PSFILENAME = tao-${TAO_VERSION}-dependencies.ps
GZIP_ENV = --best

EXTRA_DIST = Dependencies.tex

CLEANFILES = \
	Dependencies.dvi \
	Dependencies.ps \
	Dependencies.log \
	Dependencies.idx \
	Dependencies.ind \
	Dependencies.toc \
	Dependencies.lof \
	Dependencies.aux \
	${HTMLARNAME}.tgz \
	Dependencies.ps.gz

html:	html/Dependencies.html

ps:	Dependencies.ps

html-archive: html/Dependencies.html
	mkdir /tmp/${HTMLARNAME}
	cp html/*.html html/*.gif /tmp/${HTMLARNAME}
	cd /tmp ; ${TAR} czvf ${HTMLARNAME}.tar.gz ${HTMLARNAME}
	mv /tmp/${HTMLARNAME}.tar.gz .
	rm -rf /tmp/${HTMLARNAME}

psgzip: Dependencies.ps
	gzip ${GZIP_ENV} Dependencies.ps
	mv Dependencies.ps.gz ${PSFILENAME}.gz

html/Dependencies.html: ${EXTRA_DIST}
	hyperlatex Dependencies

Dependencies.dvi: ${EXTRA_DIST}
	latex Dependencies
	latex Dependencies
	makeindex Dependencies
	latex Dependencies

Dependencies.ps: Dependencies.dvi
	allneeded Dependencies.dvi
	dvips -f <Dependencies.dvi >Dependencies.ps


downloads: psgzip html-archive

.PHONY: html ps html-archive psgzip

