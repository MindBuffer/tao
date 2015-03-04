SUBDIRS = UserManual Dependencies ClassReference

EXTRA_DIST = taomanual.css \
	AdditionalInstallNotes.txt

html:
	cd UserManual && make html
	cd Dependencies && make html

html-archives:
	cd UserManual && make html-archive
	cd Dependencies && make html-archive

ps:
	cd UserManual && make ps
	cd Dependencies && make ps

psgzips:
	cd UserManual && make psgzip
	cd Dependencies && make psgzip

download-docs: html-archives psgzips

docs: ps html

alldocs: docs download-docs


