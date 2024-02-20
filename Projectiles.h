#ifndef PROJECTILES_H
#define PROJECTILES_H

#include <SDL2/SDL.h>
#include <vector>
#include "Hitbox.h"

class Projectile {
    public:
        int Length = 30, Width = 6;
        int velocity = 5;
        int x, y;
        bool isActive = true;
        Hitbox hitbox;

        Projectile();
        Projectile(int initialX, int initialY);

        void Move();
        void Render(SDL_Renderer* renderer);
};

#endif // PROJECTILES_H