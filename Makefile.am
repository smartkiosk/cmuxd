ACLOCAL_AMFLAGS = -I m4
EXTRA_DIST = generate-gitfiles.sh

SUBDIRS = include libcmux cmuxcontrold

dist-hook:
	sh $(top_srcdir)/generate-gitfiles.sh $(top_srcdir) $(distdir)