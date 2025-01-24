#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>
#include <SDL2/SDL.h>


class GameManager {
private:
    // SDL Content
    SDL_Renderer* renderer;
    SDL_Window* window;
    SDL_Texture* spriteSheetTexture;

public:
    // Class Basics
    GameManager();
    ~GameManager();
    void cleanUpSDL();

    // SDL 
    void init();
    void initWindow();
    void initRenderer();

    // Sprite Sheet
    void loadSpriteSheet(const char* spriteSheetPath);
    SDL_Texture* getSpriteSheet() const;

    // Utiltiy
    SDL_Renderer* getRenderer() const;

};
#endif // GAMEMANAGER_H