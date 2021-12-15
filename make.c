#include "make.h"

#define CC "cc"
#define CFLAGS "-Wall", "-Wextra", "-std=c11", "-pedantic"
#define LIBS "-lSDL2_image", "-lSDL2"

int main(int argc, char **argv)
{
    make_rebuild(argc, argv);
    make_assert(argc > 1, "no subcommand provided");

    if (strcmp(argv[1], "build") == 0) {
        make_cc("iv", "iv.c", CFLAGS, LIBS);
    } else if (strcmp(argv[1], "run") == 0) {
        make_assert(argc > 2, "no input image path provided");
        make_cc("iv", "iv.c", CFLAGS, LIBS);
        make_cmd("./iv", argv[2]);
    } else {
        make_error("unknown subcommand `%s`", argv[1]);
    }
}
