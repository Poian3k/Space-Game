#include "Powerups.h"

Powerup::Powerup(int screenWidth) {
    x = rand() % screenWidth;// the seed is set in the main loop
    y = 0;
    velocity = 1;
    width = 20;
    length = 20;
    hitbox = Hitbox(x,y,width,length);
    isActive = true;
}

void Powerup::Move(int screenHeight) {
    if(y < screenHeight){
        y += velocity;
        hitbox.rect.y = y;
    }else{
        isActive = false;
    }
}

void Powerup::Create(std::vector<Powerup>& powerups, int screenWidth, int points, int &powlev) {//static can be called whitout a ship istance
    if(points % 10 == 0 && powlev == 1 && points != 0){
        Powerup power(screenWidth);
        powerups.push_back(power);
        powlev ++;
    }
    if(points % 10 != 0){
        powlev = 1;
    }
}


void Powerup::Render(SDL_Renderer* renderer) {
    if (!isActive) {
        return;  // Skip rendering inactive powerups
    }
    SDL_Rect powerup = { x, y, width, length };
    SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
    SDL_RenderFillRect(renderer, &powerup);
}
