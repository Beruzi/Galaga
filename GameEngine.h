#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <SDL2/SDL.h>

class GameEngine {
private:
    // SDL Resources
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* spriteSheet;

public:
    // Class Things
    GameEngine();
    ~GameEngine();

    // Game Enging Core Functionality
    bool init(char* windowTitle, int width, int height);
    bool loadSpriteSheet(char* texturePath);
    void shutdown();

    // Get SDL Resources
    SDL_Window* getWindow();
    SDL_Renderer* getRenderer();
    SDL_Texture* getSpriteSheet();
};

#endif // GAMEENGINE_H
