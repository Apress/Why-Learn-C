# Why Learn C --- Source Code

This directory contains
the C source code
for the larger examples
used in the book
_Why Learn C_.

The source files are arranged
to make direct inclusion
into a LaTeX document
via the `\lstinputlisting` command
easy.
Specifically,
larger examples
are split into several files
so each can be included seperately.

That's also why most are `.h` files
rather than `.c` files.
If they were `.c` files,
`clang` would warn
about including a `.c` file.
