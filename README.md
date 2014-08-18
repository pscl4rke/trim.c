
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


Development
-----------

Build with:

    $ make

Testing is done with `cram`.  Run with:

    $ make test


