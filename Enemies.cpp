#include "Enemies.h"

EnemyShip::EnemyShip(int screenWidth) {
    x = rand() % (screenWidth - 40)+20;// the seed is set in the main loop
    y = 0;
    velocity = 1;
    width = 20;
    length = 80;
    hitbox = Hitbox(x,y,width,length);
    isActive = true;
}

int EnemyShip::Move(int screenHeight) {
    if(y < screenHeight){
        y += velocity;
        hitbox.rect.y = y;
    }else{
        isActive = false;
        return 1;
    }
    return 0;
}

void EnemyShip::Create(std::vector<EnemyShip>& enemies, int screenWidth, int count, int difficulty) {//static can be called whitout a ship istance
    if(count % (600-difficulty*50) == 0){
        EnemyShip enemy(screenWidth);
        enemies.push_back(enemy);
    }
}


void EnemyShip::Render(SDL_Renderer* renderer) {
    if (!isActive) {
        return;  // Skip rendering inactive projectiles
    }
    SDL_Rect Eship = { x, y, width, length };
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &Eship);
}
