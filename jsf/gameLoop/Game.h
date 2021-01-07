//
// Created by jason on 07/01/2021.
//

#include <iostream>
#include <SDL2/SDL.h>
#ifndef GAME_GAMELOOP_H
#define GAME_GAMELOOP_H


class Game {

    public:
        Game();
        ~Game();

        void init(const char* title, int xpos, int ypos, int width, int hight, bool fullscreen);

        void eventHandler();
        void update();
        void render();
        void clean();

        bool running();

    private:
        bool isRunning;
        SDL_Window  *window;
        SDL_Renderer *renderer;
};


#endif //GAME_GAMELOOP_H
