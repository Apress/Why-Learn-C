##
#	"Why Learn C"
#	Makefile.am
#
#	Copyright (C) 2025  Paul J. Lucas
#
#	This program is free software: you can redistribute it and/or modify
#	it under the terms of the GNU General Public License as published by
#	the Free Software Foundation, either version 3 of the License, or
#	(at your option) any later version.
#
#	This program is distributed in the hope that it will be useful,
#	but WITHOUT ANY WARRANTY; without even the implied warranty of
#	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#	GNU General Public License for more details.
#
#	You should have received a copy of the GNU General Public License
#	along with this program.  If not, see <http://www.gnu.org/licenses/>.
##

ACLOCAL_AMFLAGS=	-I m4
SUBDIRS=		lib src

EXTRA_DIST=		979-8-8688-1596-6.jpg \
			bootstrap \
			Contributing.md \
			Errata.md \
			m4/gnulib-cache.m4 \
			m4/update_m4.sh \
			README.md \
			src/handy

.PHONY: build update-gnulib

all: build

build:
	$(MAKE) -C src

update-gnulib:
	gnulib-tool --add-import --no-vc-files

# vim:set noet sw=8 ts=8:
