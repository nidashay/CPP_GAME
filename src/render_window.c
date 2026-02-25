#include "render_window.h"
#include <stdio.h>

void initWindow(RenderWindow* window, const char* title, int width, int height)
{
    window->window = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width,
        height,
        SDL_WINDOW_SHOWN
    );

    window->renderer = SDL_CreateRenderer(window->window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* loadTexture(RenderWindow* window, const char* filePath)
{
    SDL_Surface* surface = IMG_Load(filePath);
    if (!surface) {
        printf("Failed to load image: %s\n", IMG_GetError());
        return NULL;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, surface);
    SDL_FreeSurface(surface);

    return texture;
}

void clearWindow(RenderWindow* window)
{
    SDL_RenderClear(window->renderer);
}

void renderTexture(RenderWindow* window, SDL_Texture* texture)
{
    SDL_RenderCopy(window->renderer, texture, NULL, NULL);
}

void displayWindow(RenderWindow* window)
{
    SDL_RenderPresent(window->renderer);
}

void cleanupWindow(RenderWindow* window)
{
    SDL_DestroyRenderer(window->renderer);
    SDL_DestroyWindow(window->window);
}