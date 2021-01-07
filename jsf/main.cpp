#include <iostream>
#include <SDL2/SDL.h>


int main() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("Akuma", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, true);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,0);

    SDL_SetRenderDrawColor(renderer, 255, 100, 0,255);
    SDL_RenderPresent(renderer);

    SDL_Delay(3000);

}
