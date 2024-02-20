#include "Asteroids.h"

Asteroid::Asteroid(int screenWidth, int screenHeight){
    //set spawn point
    if(rand() % 2){
        x = rand() %  screenWidth; 
        y = 0;
    }else{
        y = rand() % (screenHeight/2);
        if(rand() % 2){
            x = 0;
        }else{
            x = screenWidth;
        }
    }

    dx = rand() % 2;

    isActive = true;
    length = (rand() % 80) + 40;//FROM 40 TO 120
    width = length;
    hitbox = Hitbox(x,y,width,length);
};

void Asteroid::Move(int screenWidth, int screenHeight){
    if(x > 0 && x < screenWidth && y >= 0 && y < screenHeight){
        if(dx){
            x += 1;
        }else{
            x -= 1;
        }
        y += 1;
        hitbox.rect.x = x;
        hitbox.rect.y = y;
    }else{
        isActive = false;
    }
}

void Asteroid::Create(std::vector<Asteroid>& asteroids, int screenWidth, int screenHeigth, int count, int difficulty, int points) {//static can be called whitout a ship istance
    if(points > 20-(difficulty*5) && ((count % 1000) == 0)){
        Asteroid aste(screenWidth, screenHeigth);
        asteroids.push_back(aste);
    }
}

void Asteroid::Render(SDL_Renderer* renderer) {
    if (!isActive) {
        return;  // Skip rendering inactive projectiles
    }
    SDL_Rect Aster = { x, y, width, length };
    SDL_SetRenderDrawColor(renderer, 165, 42, 42, 255);
    SDL_RenderFillRect(renderer, &Aster);
}
