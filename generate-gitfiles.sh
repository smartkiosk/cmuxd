#!/bin/sh

set -e

top_srcdir="$1"
distdir="$2"

# check for git
which git >/dev/null 2>&1 || exit 0

if [ `wc -l "${distdir}/ChangeLog" | cut -d ' ' -f 1` -eq 0 ]; then
	echo "Generating ChangeLog"

	git log --date=iso8601 --format="%ad  %cN <%cE>%n%n%w(72,4)%B%n" > ${distdir}/ChangeLog
fi

if [ `wc -l "${distdir}/AUTHORS" | cut -d ' ' -f 1` -eq 0 ]; then
	echo "Generating AUTHORS"

	git log --format='%cN <%cE>' | sort -u > ${distdir}/AUTHORS
fi
