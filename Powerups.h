#ifndef POWERUP_H
#define POWERUP_H

#include <iostream>
#include <SDL2/SDL.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Hitbox.h"

class Powerup {
public:
    int x, y, velocity, width, length;
    Hitbox hitbox;
    bool isActive;
    
    Powerup(int screenWidth);
    void Move(int screenHeight);
    static void Create(std::vector<Powerup>& powerups, int screenWidth, int points, int &powlev);
    void Render(SDL_Renderer* renderer);

    
};

#endif // POWERUP_H