
// trim.c -- (c) 2014 P. S. Clarke -- Released under GNU GPLv3

#include <stdio.h>
#include <sys/ioctl.h>

#define DEFAULTLINESIZE 80

int get_line_size (void) {
    struct winsize data = { 0, 0, 0, 0 };

    ioctl(fileno(stdout), TIOCGWINSZ, &data);
    if (data.ws_col > 0) {
        return data.ws_col;
    } else {
        return DEFAULTLINESIZE;
    }
}

int trim (int width) {
    int c; // not char, so it works on raspi
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
        width = get_line_size();
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


