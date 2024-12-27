// C++ Libs
#include <iostream>

// Third Party Libs
#include <SDL2/SDL.h>

int main(){

    // Create the Window 
    SDL_Window* window = nullptr; 
    window = SDL_CreateWindow("Galaga", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 480, 640, SDL_WINDOW_SHOWN);   

    // Game loop
    bool gameIsRunning = true;
    while (gameIsRunning){  
        SDL_Event event;
        // Start the event loop and handle events
        while(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT){
                gameIsRunning = false;
            }
        }
    }

    // Cleanup -- note the C style coding because SDL2 is a C-style API
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}