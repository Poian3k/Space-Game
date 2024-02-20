#include "Projectiles.h"

Projectile::Projectile(){};
Projectile::Projectile(int initialX, int initialY) : x(initialX), y(initialY){
    hitbox = Hitbox(x,y,Width,Length);
};

void Projectile::Move() {
    if(y > 0){
        y -= velocity;
        hitbox.rect.y = y;
    }
    else {
        isActive = false;  // Set the projectile as inactive
    }
}

void Projectile::Render(SDL_Renderer* renderer) {
    if (!isActive) {
        return;  // Skip rendering inactive projectiles
    }
    SDL_Rect proj = { x, y, Width, Length };
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &proj);
}
    