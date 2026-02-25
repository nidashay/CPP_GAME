#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "render_window.h"

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0) {
        printf("Yay, SDL has failed: %s\n", SDL_GetError());
    } else {
        printf("SDL has initialized successfully\n");
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        printf("Yay, SDL_image has failed: %s\n", IMG_GetError());
    } else {
        printf("SDL_image has initialized successfully\n");
    }

    RenderWindow window;
    initWindow(&window, "Arthur v0.0.1 BETA", 800, 600);

    SDL_Texture* playerTexture = loadTexture(&window, "./assets/player.png");
    SDL_Texture* groundTexture = loadTexture(&window, "./assets/ground.png");

    bool gameRunning = true;
    SDL_Event event;

    while (gameRunning) {

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                gameRunning = false;
            }
        }

        clearWindow(&window);
        renderTexture(&window, playerTexture);
        displayWindow(&window);
    }

    cleanupWindow(&window);

    IMG_Quit();
    SDL_Quit();

    return 0;
}