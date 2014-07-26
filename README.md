
trim.c
======

Unix pipeline tool for trimming long lines (C implementation)


Usage
-----

For example:

    $ cat widefile | trim | less
    $ cat widefile | trim 130 | less

The optional first argument specifies a width.


Limitations
-----------

* No man page.
* Inability to detect terminal window size.


Development
-----------

Testing is done with `cram`.  Run with:

    $ make test


