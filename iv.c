#include <stdlib.h>
#include <stdbool.h>

#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "usage: iv IMAGE\n");
        exit(1);
    }

    SDL_Init(SDL_INIT_VIDEO);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    SDL_Window *window = SDL_CreateWindow(argv[1], 0, 0, 800, 600, SDL_WINDOW_RESIZABLE);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    IMG_Init(IMG_INIT_PNG);
    SDL_Texture *texture = IMG_LoadTexture(renderer, argv[1]);

    int image_width = 0;
    int image_height = 0;
    SDL_QueryTexture(texture, NULL, NULL, &image_width, &image_height);
    SDL_RenderSetLogicalSize(renderer, image_width, image_height);

    bool running = true;
    SDL_Event event;
    while (running) {
        SDL_WaitEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                running = false;
                break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case 'q':
                        running = false;
                        break;
                }
                break;
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }

    IMG_Quit();

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
