#ifndef RENDER_WINDOW_H
#define RENDER_WINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
} RenderWindow;

void initWindow(RenderWindow* window, const char* title, int width, int height);
SDL_Texture* loadTexture(RenderWindow* window, const char* filePath);
void clearWindow(RenderWindow* window);
void renderTexture(RenderWindow* window, SDL_Texture* texture);
void displayWindow(RenderWindow* window);
void cleanupWindow(RenderWindow* window);

#endif