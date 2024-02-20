#include "Ship.h"

Ship::Ship(int initialX, int initialY) : x(initialX), y(initialY), Length(80), Width(20) {
    hitbox = Hitbox(x, y, Width, Length);
    cooldown = 0;
}


void Ship::Move(int height, int length) {
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    if (currentKeyStates[SDL_SCANCODE_W]) {
        y -= 2;
        hitbox.rect.y = y;
    }
    if (currentKeyStates[SDL_SCANCODE_S]) {
        y += 2;
        hitbox.rect.y = y;
    }
    if (currentKeyStates[SDL_SCANCODE_A]) {
        x -= 2;
        hitbox.rect.x = x;
    }
    if (currentKeyStates[SDL_SCANCODE_D]) {
        x += 2;
        hitbox.rect.x = x;
    }

    if (y < (height/2) - Length) {
        y = (height/2) - Length;
        hitbox.rect.y = y;
    }
    else if (y > height - Length) {
        y = height - Length;
        hitbox.rect.y = y;
    }
    if (x < 0) {
        x = 0;
    }
    else if (x > length - Width) {
        x = length - Width;
        hitbox.rect.x = x;
    }
}


void Ship::Fire(std::vector<Projectile>& projectiles, int shipLev) {
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    if (currentKeyStates[SDL_SCANCODE_SPACE] && cooldown <= 0) {
        switch (shipLev) {
            case 1: {
                Projectile proj(x + Width/2 - 3, y - 30);//-3 because the proj width is 6
                projectiles.push_back(proj);
                break;
            }
            case 2: {
                Projectile proj(x - Width/2 - 3, y - 30);
                projectiles.push_back(proj);
                Projectile proj2(x + Width*3/2 - 3, y - 30);
                projectiles.push_back(proj2);
                break;
            }
        }
        cooldown = 10;
    }
    if (cooldown > 0) {
        cooldown--;
    }
}

void Ship::Render(SDL_Renderer* renderer, int shipLev) {
    SDL_Rect ship;
    switch(shipLev){
        case 1:
            ship = { x, y, Width, Length };
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);//blue
            SDL_RenderFillRect(renderer, &ship);
            break;
        case 2:
            SDL_Rect rigth = { x - Width, y, Width, Length };
            SDL_Rect left = { x + Width, y, Width, Length };
            SDL_Rect middle = { x - Width/4*3, y + Length/4*3, Width*2, 10 };         
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // blue
            SDL_RenderFillRect(renderer, &rigth);
            SDL_RenderFillRect(renderer, &left);
            SDL_RenderFillRect(renderer, &middle);
            hitbox.rect.x = left.x;
            hitbox.rect.w = Width*3;
            break;
    } ;
}
      