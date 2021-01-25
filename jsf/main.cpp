#include <iostream>
#include "src/Game.h"


int main() {

    Game* game = new Game();

    game -> init("Akumas first src", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED , 500, 500, false);

    const int FRP = 60;
    const int frameDelay = 1000/FRP;

    Uint64 frameStart;
    int frameTime;


    while(game -> running()){

        frameStart = SDL_GetTicks();

        game -> eventHandler();
        game -> update();
        game -> render();

        frameTime = SDL_GetTicks() - frameStart;
        if(frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game -> clean();

    return 0;
}
