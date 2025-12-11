#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_image.h>
#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char* p_title, int p_Width, int p_Height)
    :window(NULL), renderer(NULL)
{

    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_Width, p_Height, SDL_WINDOW_SHOWN);

    if(window == NULL){

        std::cout << "Window failed to Init. Error: " << SDL_GetError() << std::endl;

    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{

    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filePath);

    if(texture == NULL){

        std::cout << "Failed to load textures. Error: " << SDL_GetError() << std::endl;

    }

    return texture;

}

void RenderWindow::cleanUp()
{

    SDL_DestroyWindow(window);

}

void RenderWindow::clear()
{

    SDL_RenderClear(renderer);

}

void RenderWindow::render(SDL_Texture* p_texture)
{

    SDL_Rect src_p_textureRect;
    
    src_p_textureRect.x = 0;
    src_p_textureRect.y = 0;
    src_p_textureRect.w = 32;
    src_p_textureRect.h = 32;

    SDL_Rect dst_p_textureRect;
    
    dst_p_textureRect.x = 50;
    dst_p_textureRect.y = 50;
    dst_p_textureRect.w = 32;
    dst_p_textureRect.h = 32;

    SDL_RenderCopy(renderer, p_texture, &src_p_textureRect, &dst_p_textureRect);

}

void RenderWindow::display()
{

    SDL_RenderPresent(renderer);

}