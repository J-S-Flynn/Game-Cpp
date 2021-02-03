//
// Created by jason on 28/01/2021.
//
#pragma once
#include "Game.h"

class TextureManager{

    public:
        static SDL_Texture * loadTexture(const char* fileName, SDL_Renderer* ren);
};