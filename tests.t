

vim:ft=txt:et:sw=2:

This is a cram-formatted test suite.

  $ echo hello | $TESTDIR/trim 10
  hello

  $ echo hello there | $TESTDIR/trim 10
  hello ther

  $ echo -n hi | $TESTDIR/trim 5
  hi (no-eol)

  $ $TESTDIR/trim 20 <<EOF
  > 1234567890123456789012345
  > This is some
  > text that should be
  > trimmed to 20 columns
  > wide.
  > EOF
  12345678901234567890
  This is some
  text that should be
  trimmed to 20 column
  wide.


