INCS=sdl2 SDL2_image
CFLAGS=-Wall -Wextra -std=c11 -pedantic -ggdb `pkg-config --cflags $(INCS)`
LIBS=-lm `pkg-config --libs $(INCS)`

iv: iv.c
	$(CC) $(CFLAGS) -o iv iv.c $(LIBS)
