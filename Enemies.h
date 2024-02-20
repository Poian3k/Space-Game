#ifndef ENEMIES_H
#define ENEMIES_H

#include <SDL2/SDL.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Hitbox.h"

class EnemyShip {
public:
    EnemyShip(int screenWidth);
    int Move(int screenHeight);
    static void Create(std::vector<EnemyShip>& enemies, int screenWidth, int count, int difficulty);
    void Render(SDL_Renderer* renderer);
    

    int x, y, velocity, width, length;
    Hitbox hitbox;
    bool isActive;
    int stillAlive;
};

#endif // ENEMIES_H