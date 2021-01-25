//
// Created by jason on 07/01/2021.
//

#include "Game.h"

    int cnt = 0;
    int screenSize = 0;

    SDL_Rect srcRect, destRect;
    SDL_Texture* loadingScreen = nullptr;

    Game::Game() {}
    Game::~Game() {}



    void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {

        if (fullscreen) {
            screenSize = SDL_WINDOW_FULLSCREEN;
        }

        if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

            std::cout << "Subsystem is started Boss.. lets go" << std::endl;

            window = SDL_CreateWindow(title, xpos, ypos, width, height, screenSize);
            if (window) {

                std::cout << "constricted window..." << std::endl;
            }

            renderer = SDL_CreateRenderer(window, -1, 0);
            if (renderer) {

                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

                std::cout << "constructed and deployed renderer boss. we are running" << std::endl;
            }

            SDL_Surface* tempSurface = IMG_Load("jsf/assets/digiScribble.jpg");
            if(tempSurface == NULL){
                std::cout << "there was no image at the location folder" << std::endl;
            }

            loadingScreen = SDL_CreateTextureFromSurface(renderer, tempSurface);
            SDL_FreeSurface(tempSurface);

            isRunning = true;
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

        destRect.w = destRect.h = 500;


        if(cnt < 510){

            if(cnt%2 == 0){

                SDL_SetTextureBlendMode(loadingScreen, SDL_BLENDMODE_BLEND);

                SDL_SetTextureAlphaMod(loadingScreen, alpha);
                alpha++;
            }
            std::cout << alpha << std::endl;
            cnt++;

        }
    }

    void Game::render() {

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, loadingScreen, nullptr, &destRect);
        SDL_RenderPresent(renderer);
    }

    void Game::clean() {

        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        SDL_Quit();

        std::cout << "destroying the src Boss" << std::endl;
    }

    bool Game::running() const {
        return isRunning;
    }
