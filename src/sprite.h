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

    SDL_FRect rect;
    SDL_Rect srcRect;
    SDL_Renderer *renderer;

public:
    /**
     * Default Constructor
     * @brief Constructor for Abstract Sprite Class
     * @param x the x position for the sprite to appear on the window
     * @param y the y position for the sprite to appear on the window
     * @param w the width of the sprite
     * @param h the height of the sprite
     * @param renderer the renderer to be used
     *
     */
    Sprite(float x, float y, float w, float h, SDL_Renderer *renderer)
        : renderer(renderer) {
        rect = {x, y, w, h};
        srcRect = {0, 0, static_cast<int>(w), static_cast<int>(h)};
    }

    // Destructor
    virtual ~Sprite() {
        if (spriteSheetTexture) {
            SDL_DestroyTexture(spriteSheetTexture);
        }
        spriteSheetTexture = nullptr;
    }


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
     * @brief Render the sprite to screen...
     */
    void Render() {
        SDL_Rect intRect = toSDL_Rect();
        SDL_RenderCopy(renderer, spriteSheetTexture, &srcRect, &intRect);
    }

    /**
     * @brief Converts an SDL_FRect to an SDL_Rect (SDL2 doesn't have any function for this)
     */
    SDL_Rect toSDL_Rect() const{
        return SDL_Rect{
            static_cast<int>(rect.x),
            static_cast<int>(rect.y),
            static_cast<int>(rect.w),
            static_cast<int>(rect.h)
        };
    }
};

// Initialize Static Members:
SDL_Texture *Sprite::spriteSheetTexture = nullptr;
