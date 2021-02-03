//
// Created by jason on 07/01/2021.
//
#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"

    int screenSize = 0;

    GameObject* player;

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

                std::cout << "constructed window..." << std::endl;
            }

            renderer = SDL_CreateRenderer(window, -1, 0);
            if (renderer) {

                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

                std::cout << "constructed and deployed renderer boss. we are running" << std::endl;
            }
            isRunning = true;
        }

        player = new GameObject("jsf/assets/raz.png", renderer);
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

        player -> Update();
    }

    void Game::render() {

        SDL_RenderClear(renderer);
        player -> Render();
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
