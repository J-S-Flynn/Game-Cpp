//
// Created by jason on 07/01/2021.
//

#include <iostream>
#include <unistd.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#ifndef GAME_SRC_H
#define GAME_SRC_H

class Game {

    public:
        Game();
        ~Game();

        void showSplashScreen();
        void init(const char* title, int xpos, int ypos, int width, int hight, bool fullscreen);

        void eventHandler();
        void update();
        void render();
        void clean();

        bool running() const;

    private:
        int alpha;
        bool isRunning;
        SDL_Window  *window;
        SDL_Renderer *renderer;
};


#endif //GAME_SRC_H
