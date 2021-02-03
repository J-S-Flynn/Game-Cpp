//
// Created by jason on 28/01/2021.
//
#pragma once
#include "Game.h"

class GameObject{

    public:
        GameObject(const char* textureSheet, SDL_Renderer* ren);
        ~GameObject();

        void Update();
        void Render();

    private:
        int xPos;
        int yPos;

        SDL_Texture* objTexture;
        SDL_Renderer*  renderer;
        SDL_Rect srcRect, dstRect;
};