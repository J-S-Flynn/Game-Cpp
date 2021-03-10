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

    int tWidth;
    int tHeight;

    SDL_QueryTexture(objTexture, NULL, NULL, &tWidth, &tHeight);
    xPos = 0;
    yPos = 0;

    srcRect.w = tWidth;
    srcRect.h = tHeight;
    srcRect.x = 0;
    srcRect.y = 0;

    dstRect.w = srcRect.w / 3 ;
    dstRect.h = srcRect.h / 3 ;
    dstRect.x = xPos;
    dstRect.y = yPos;
}

void GameObject::Render() {

    SDL_RenderCopy(renderer, objTexture, &srcRect, &dstRect);
}