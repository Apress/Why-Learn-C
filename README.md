# Apress Source Code

This repository accompanies
[*Why Learn C*](https://link.springer.com/book/9798868815966)
by
[Paul J. Lucas](https://github.com/paul-j-lucas)
(Apress, 2025).

[comment]: #cover
![Cover image](979-8-8688-1596-6.jpg)

Download the files using the green button,
or clone the repository to your machine using Git.

## Releases

Releases are numbered using a form of
[semantic versioning](https://semver.org)
except instead of _major_._minor_._patch_,
_edition_._errata_._patch_
is used instead where:

+ _edition_ corresponds to the edition of the published book,
  e.g., 1 = first edition, etc.
+ _errata_ corresponds to a correction mentioned in the
  [errata](https://github.com/Apress/Why-Learn-C/blob/main/Errata.md)
  for the published book.
+ _patch_ corresponds to an update
  only to the “support” files
  in this respository,
  but _not_ in the published book,
  e.g., makefiles,
  Autoconf macros,
  Gnulib source files,
  etc.

For example,
release [1.0](https://github.com/Apress/Why-Learn-C/releases/tag/wlc-1.0)
corresponds to the initial code
in the first edition
without corrections;
release [1.0.1](https://github.com/Apress/Why-Learn-C/releases/tag/wlc-1.0.1)
corresponds to updates
to
command-line options in makefiles
and
Autoconf macros,
but no corrections to the published book;
etc.

## Installation

Many of the C examples are compiled
and some are tested
to ensure they're syntactically
and semantically
correct.
A C compiler capable of compiling C23
via the `-std=c23` option is required.

The git repository contains only the necessary source code.
Things like `configure` are _derived_ sources and
[should not be included in repositories](http://stackoverflow.com/a/18732931).
If you have
[`autoconf`](https://www.gnu.org/software/autoconf/),
[`automake`](https://www.gnu.org/software/automake/),
and
[`m4`](https://www.gnu.org/software/m4/)
installed,
you can generate `configure` yourself by doing:

    ./bootstrap

or you can download a
[released version](https://github.com/Apress/Why-Learn-C/releases)
that contains `configure`.

After that:

    ./configure

If you need to use a compiler
other than the first `gcc`
found in the `PATH` environment variable,
specify it via `CC`, e.g.:

    ./configure CC=clang

Finally,
to build
the source code
for the larger examples:

    make

If you get linker errors
like "undefined reference to `__atomic_load`",
add `LDFLAGS=-latomic`
to your `configure` command.

Optionally,
you can also run unit tests
for the larger examples:

    make check

## Contributions

See the file
[`Contributing.md`](https://github.com/Apress/Why-Learn-C/blob/main/Contributing.md)
for more information
on how you can contribute
to this repository.

## Errata

See the file
[`Errata.md`](https://github.com/Apress/Why-Learn-C/blob/main/Errata.md)
for errata
to the published book.
