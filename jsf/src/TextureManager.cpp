//
// Created by jason on 28/01/2021.
//

#include "TextureManager.h"

SDL_Texture* TextureManager::loadTexture(const char* texture, SDL_Renderer* ren) {

    SDL_Surface* surface = IMG_Load(texture);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, surface);

    SDL_FreeSurface(surface);

    return tex;
}