#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "RenderWindow.hpp"

int main(int argc, char* argv[])
{
    if(SDL_Init(SDL_INIT_VIDEO) > 0){

        std::cout << "Yay, SDL has failed" << SDL_GetError() << std::endl;

    }else{

        std::cout << "SDL has compiled successfully" << std::endl;

    }

    if(!(IMG_Init(IMG_INIT_PNG))){

        std::cout << "Yay, SDL_Image has failed" << SDL_GetError() << std::endl;

    }else{

        std::cout << "SDL_Image has compiled successfully" << std::endl;

    }

    RenderWindow window("Arthur v0.0.1 BETA", 800, 600);

    SDL_Texture* playerTexture = window.loadTexture("./assets/player.png");
    SDL_Texture* groundTexture = window.loadTexture("./assets/ground.png");


    bool gameRunning = true;

    SDL_Event event;

    while(gameRunning){

        while(SDL_PollEvent(&event)){

            if(event.type == SDL_QUIT){

                gameRunning = false;

            }

        }

        window.clear();

        window.render(playerTexture);

        window.display();

    }

    window.cleanUp();

    SDL_Quit();

    return 0;
}
