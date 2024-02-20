#ifndef ASTEROIDS_H
#define ASTEROIDS_H

#include <cstdlib>
#include <ctime>
#include <vector>
#include <SDL2/SDL.h>
#include "Hitbox.h"

class Asteroid{
    public:
        int x,y, length, width;
        bool dx, isActive;
        Hitbox hitbox;


        Asteroid(int screenWidth, int screenHeight);
        void Move(int screenWidth, int screenHeight);
        static void Create(std::vector<Asteroid>& asteroids, int screenWidth, int screenHeigth, int count, int difficulty, int points);
        void Render(SDL_Renderer* renderer);

};

#endif //ASTEROIDS_H