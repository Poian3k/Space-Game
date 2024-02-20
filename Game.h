#include <SDL2/SDL.h>

void pause(SDL_Event &event, SDL_Renderer* renderer, const Uint8* &keyStates, bool &quit);

void lifeCount(SDL_Renderer* renderer, int lifelimit, bool &quit, int WIDTH);