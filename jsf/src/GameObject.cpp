//
// Created by jason on 28/01/2021.
//

#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* textureSheet, SDL_Renderer *ren) {

    renderer = ren;
    objTexture = TextureManager::loadTexture(textureSheet, ren);
}

void GameObject::Update() {

    xPos = 0;
    yPos = 0;

    srcRect.w = 300;
    srcRect.h = 400;
    srcRect.x = 0;
    srcRect.y = 0;

    dstRect.w = srcRect.w / 4 ;
    dstRect.h = srcRect.h / 4 ;
    dstRect.x = xPos;
    dstRect.y = yPos;
}

void GameObject::Render() {

    SDL_RenderCopy(renderer, objTexture, &srcRect, &dstRect);
}