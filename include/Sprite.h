#ifndef SPRITE_H
#define SPRITE_H

#include <iostream>
#include <SDL2/SDL.h>

/**
 * @brief Abstract Class to be inherited by any sprite related object (player, enemy, missle, etc.)
 * @details Contains members rect and srcRect that act as the bounds (location and dimensions) for sprites
 * and the bounds for where to find the sprite on the spritesheet.
 */
class Sprite {
protected:
    static SDL_Texture* spriteSheetTexture;  // Shared resource for all sprites
    static int spriteCount;

    SDL_FRect winRect;      
    SDL_Rect srcRect;   
    SDL_Renderer* renderer;

public:
    /**
     * @brief Constructor for the Sprite Class
     * @param x X-coordinate of the sprite on the screen
     * @param y Y-coordinate of the sprite on the screen
     * @param w Width of the sprite
     * @param h Height of the sprite
     * @param renderer SDL_Renderer for rendering operations
     */
    Sprite(float x, float y, float w, float h, SDL_Renderer* renderer);

    /**
     * @brief Virtual Destructor for Sprite
     */
    virtual ~Sprite();

    /**
     * @brief Loads the entire sprite sheet for all children to share
     * @param renderer SDL_Renderer used for creating the texture
     * @param spriteSheetPath Path to the sprite sheet file
     */
    static void LoadSpriteSheet(SDL_Renderer* renderer, const char* spriteSheetPath);

    /**
     * @brief Sets the source rectangle on the sprite sheet for this sprite
     * @param x X-coordinate on the sprite sheet
     * @param y Y-coordinate on the sprite sheet
     * @param w Width of the rectangle
     * @param h Height of the rectangle
     */
    void setSourceRect(int x, int y, int w, int h);

    void setWindRect(float x, float y, float w, float h);

    const SDL_FRect& getWindRect();

    /**
     * @brief Renders the sprite onto the screen
     */
    void render();

    /**
     * @brief Converts the SDL_FRect to SDL_Rect
     * @return An SDL_Rect corresponding to the SDL_FRect dimensions
     */
    SDL_Rect toSDL_Rect() const;


    /**
     * @brief Just a Print statement to monitor sprite members in terminal
     */
    void print();
};

#endif 
