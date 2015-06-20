
trim.c
======

Unix pipeline tool for trimming long lines.

This is an implementation in C, and is licensed under
the GNU GPL version 3.


Usage
-----

For example:

    $ cat widefile | trim | less
    $ cat widefile | trim 130 | less

The optional first argument specifies a width.


Limitations
-----------

* No man page.
* Terminal width detection is probably not portable.
* Width detection fails when piped (e.g. into `less`).

Also, for Debian packaging, lintian complains about:

    W: trim-c: extra-license-file usr/share/doc/trim-c/LICENCE.txt.gz
    W: trim-c: binary-without-manpage usr/bin/trim


Development
-----------

Build with:

    $ make

Testing is done with `cram`.  Run with:

    $ make test

Install with:

    $ sudo make install

Alternatively install using a Debian package that you or someone
else has created.


