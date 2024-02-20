#include "Hitbox.h"

Hitbox::Hitbox(int x, int y, int width, int height) {
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;
}

bool Hitbox::CheckCollision(const Hitbox& other) const {
    return SDL_HasIntersection(&rect, &other.rect) == SDL_TRUE;
}