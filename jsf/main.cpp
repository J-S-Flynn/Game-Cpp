#include <iostream>
#include <SDL2/SDL.h>
#include "gameLoop/Game.h"


int main() {

    Game* game = new Game();

    game -> init("Akumas first game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED , 600, 400, false);

    while(game -> running()){

        game -> eventHandler();
        game -> update();
        game -> render();
    }

    game -> clean();

    return 0;

}
