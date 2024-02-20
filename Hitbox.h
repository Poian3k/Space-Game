#ifndef HITBOX_H
#define HITBOX_H

#include <SDL2/SDL.h>

struct Hitbox {
    SDL_Rect rect;  // SDL_Rect representing the hitbox position and size

    // Constructors
    Hitbox() = default;
    Hitbox(int x, int y, int width, int height);

    // Check collision with another hitbox
    bool CheckCollision(const Hitbox& other) const;
};

#endif  // HITBOX_H

