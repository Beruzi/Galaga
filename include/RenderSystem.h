#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include <iostream>
#include <SDL2/SDL.h>

#include "Entity.h"

class RenderSystem {
private:
    SDL_Renderer* renderer;
    SDL_Texture* spriteSheetTexture;
public:
    // Class Basics
    RenderSystem();
    RenderSystem(SDL_Renderer* renderer);
    ~RenderSystem();
    
    // Sprite Sheet
    void loadSpriteSheet();
    
    // Rendering
    void sceneRender();
    void render(const Entity* entity);
};

#endif // RENDERSYSTEM