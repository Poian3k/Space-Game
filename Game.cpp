#include "Game.h"

void pause(SDL_Event &event, SDL_Renderer* renderer, const Uint8* &keyStates, bool &quit){
    bool pause = true;
    while(pause){
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);//set all screen red
        SDL_RenderClear(renderer);
        SDL_PollEvent(&event);//allow to take input
        if (event.type == SDL_QUIT) {
            quit = true; // Set quit to true if the user tries to quit while paused
            pause = false;
        }
        if(keyStates[SDL_SCANCODE_Z]){//z to quit
            quit = true;
            pause = false;
        }
        if(keyStates[SDL_SCANCODE_R]){//r to resume
            pause = false;
        }
        SDL_RenderPresent(renderer);
    }
}

void lifeCount(SDL_Renderer* renderer, int lifelimit, bool &quit, int WIDTH){
    quit = true;
    for(int i = 0; i < lifelimit; i ++){//life shown
        SDL_Rect life {WIDTH - (i*50 + 50), 50, 10, 20};
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // blue
        SDL_RenderFillRect(renderer, &life);
        quit = false;//so that if the function isn't called the program ends
    }
}