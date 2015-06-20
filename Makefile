

trim: trim.c
	gcc -o trim trim.c

test:
	cram -v tests.t

install: trim
	install -D trim $(DESTDIR)/usr/bin/trim


