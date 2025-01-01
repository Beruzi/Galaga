#include <iostream>
#include <SDL2/SDL.h>

/**
 * @brief Abstract Class to be inherited by Player and Enemies
 * @details Contains members rect and srcRect that act as the bounds (location and dimensions) for sprites
 * and the bounds for where to find the sprite on the spritesheet
 */
class Sprite
{
protected:
    // made static so the children can all share the single resource
    static SDL_Texture* spriteSheetTexture;

    SDL_Rect rect;
    SDL_Rect srcRect;
    SDL_Renderer *renderer;

public:
    /**
     * @brief Constructor for Abstract Sprite Class
     * @param x the x position for the rectangle containing the texture
     * @param y the y position for the rectanlge containing the texture
     * @param w the width of the rectangle for sprite
     * @param h the height of the rectangle for sprite
     * @param renderer the renderer to be used
     *
     */
    Sprite(int x, int y, int w, int h, SDL_Renderer *renderer)
        : renderer(renderer) {
        rect = {x, y, w, h};
        srcRect = {0, 0, w, h};
    }

    // Destructor
    virtual ~Sprite() {}


public:
    /**
     * @brief Statically loads the entire sprite sheet for all subsequent children to use and render from
     */
    static void LoadSpriteSheet(SDL_Renderer* renderer, const char* spriteSheetPath) {
        // Loading BMP as a surface
        SDL_Surface *surface = SDL_LoadBMP(spriteSheetPath);
        if (!surface) {
            std::cerr << "Failed to load sprite: " << SDL_GetError() << std::endl;
            exit(1);
        }

        // Converting surface to a texture
        spriteSheetTexture  = SDL_CreateTextureFromSurface(renderer, surface);
        if (!spriteSheetTexture) {
            std::cerr << "Failed to create texture: " << SDL_GetError() << std::endl;
            exit(1);
        }

        // Destroy the Surface
        SDL_FreeSurface(surface);
    }

    /**
     * @brief Child Classes can define what portion of the sprite sheet they want to copy from
     * @param x the x position on the sprite sheet
     * @param y the y position on the sprite sheet
     * @param w the width of the sprite
     * @param h the heigh of the sprite
     */
    void setSourceRect(int x, int y, int w, int h) {
        srcRect = {x, y, w, h};
    }

    /**
     * @brief Render the sprite to screen
     */
    void Render() {
        SDL_RenderCopy(renderer, spriteSheetTexture, &srcRect, &rect);
    }
};

// Initialize Static Members:
SDL_Texture *Sprite::spriteSheetTexture = nullptr;
