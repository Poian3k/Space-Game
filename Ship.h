#ifndef SHIP_H
#define SHIP_H

#include <SDL2/SDL.h>
#include <vector>
#include "Hitbox.h"
#include "Projectiles.h"

class Ship {
public:
    int Length, Width, cooldown;
    int x, y;
    Hitbox hitbox;
    
    Ship(int initialX, int initialY);
    void Move(int height, int length);
    void Fire(std::vector<Projectile>& projectiles, int shipLev);
    void Render(SDL_Renderer* renderer, int shipLev);
};

#endif // SHIP_H