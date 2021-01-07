//
// Created by jason on 07/01/2021.
//

#include "Game.h"

Game::Game() {

    }
    Game::~Game() {

    }

    void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {

    int screenSize = 0;
    if(fullscreen){
        screenSize = SDL_WINDOW_FULLSCREEN;
    }
        if(SDL_Init(SDL_INIT_EVERYTHING) == 0){

            std::cout << "Subsystem is started Boss.. lets go" << std::endl;

            window = SDL_CreateWindow(title, xpos, ypos, width, height, screenSize);
            if(window){

                std::cout << "constricted window..." << std::endl;
            }

            renderer = SDL_CreateRenderer(window, -1, 0);
            if(renderer){

                SDL_SetRenderDrawColor(renderer, 120, 100, 125, 155);
                std::cout << "constructed and deployed renderer boss. we are running" << std::endl;
            }

            isRunning = true;
        }
        else{
            isRunning = false;
        }
    }

    void Game::eventHandler() {
        SDL_Event event;
        SDL_PollEvent(&event);

        switch (event.type) {

            case SDL_QUIT :
                isRunning = false;
                break;
            default:
                break;
        }



    }

    void Game::update() {

    }

    void Game::render() {

        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);

    }

    void Game::clean() {

        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        SDL_Quit();

        std::cout << "destroying the game Boss" << std::endl;
    }

        bool Game::running() {
            return isRunning;
        }
