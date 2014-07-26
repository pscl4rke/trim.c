
#include <stdio.h>

#define DEFAULTLINESIZE 80

int trim (int width) {
    char c;
    int i = 0;

    while ((c = getchar()) != EOF) {
        // This works, but feels ugly :(
        if (i++ < width) {
            putchar(c);
        }
        if (c == '\n') {
            i = 0;
        } else if (i == width) {
            putchar('\n');
        }
    }
    return 0;
}

int main (int argc, char *argv[]) {
    int width;

    if (argc == 1) {
        // FIXME: It would be great to get the current tty size here.
        width = DEFAULTLINESIZE;
    } else if (argc == 2) {
        if (!sscanf(argv[1], "%i", &width)) {
            fprintf(stderr, "Cannot understand '%s'\n", argv[1]);
            return 1;
        }
    } else {
        fprintf(stderr, "Too many arguments\n");
        return 1;
    }
    return trim(width);
}


