

trim: trim.c
	gcc -o trim trim.c

test:
	cram -v tests.t


