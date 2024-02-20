#include "Collision.h"


void killEnemy(std::vector<Projectile>& projectiles, std::vector<EnemyShip>& enemies, SDL_Renderer* renderer, int& points) {
    for (int i = 0; i < projectiles.size(); i++) {
        projectiles[i].Move();
        projectiles[i].Render(renderer);

        for (int j = 0; j < enemies.size(); j++) {
            if (projectiles[i].hitbox.CheckCollision(enemies[j].hitbox)) {
                // Mark the enemy ship as inactive
                enemies[j].isActive = false;
                // Mark the projectile as inactive
                projectiles[i].isActive = false;
                points++;
                break; // Exit the inner loop since the projectile can only collide with one enemy at a time
            }
        }
    }
}

void levelUp(const Ship& ship, std::vector<Powerup>& powerups, int count, int HEIGHT, int& level, SDL_Renderer* renderer) {
    bool collisionDetected = false; // Flag to track collision in the current frame
    for (int i = 0; i < powerups.size(); i++) {
        if (powerups[i].isActive) {
            if (count % 2) {
                powerups[i].Move(HEIGHT);
            }
            powerups[i].Render(renderer);
        }

        if (powerups[i].hitbox.CheckCollision(ship.hitbox) && level < 2 && !collisionDetected) {
            level++;
            powerups[i].isActive = false;
            collisionDetected = true; // Set the flag to true to prevent further increments this frame
            break;
        }
    }
}

void AsteroidInpact(Ship &ship, std::vector<Asteroid> &asteroids, int count, int WIDTH, int HEIGTH, int &lifelimit, SDL_Renderer* renderer){
    bool collisionDetected = false; // Flag to track collision in the current frame
    for (int i = 0; i < asteroids.size(); i++) {
        if(asteroids[i].isActive){
            if(count % 3){
            asteroids[i].Move(WIDTH, HEIGTH);
            }
            asteroids[i].Render(renderer);
        }
        if (asteroids[i].hitbox.CheckCollision(ship.hitbox) && !collisionDetected) {
            lifelimit -= 3;
            collisionDetected = true; // Set the flag to true to prevent further increments this frame
            break;
        }
        
    }
}


void cleanVector(std::vector<EnemyShip> &enemies){// Remove inactive enemies from the vector
    enemies.erase(std::remove_if(enemies.begin(), enemies.end(), [](const EnemyShip& enemy) {
        return !enemy.isActive;
    }), enemies.end());
}
void cleanVector(std::vector<Projectile> &projectiles){// Remove inactive projectiles from the vector
    projectiles.erase(std::remove_if(projectiles.begin(), projectiles.end(), [](const Projectile& projectile) {
        return !projectile.isActive;
    }), projectiles.end());
}
void cleanVector(std::vector<Powerup> &powerups){
    powerups.erase(std::remove_if(powerups.begin(), powerups.end(), [](const Powerup& pow) {
        return !pow.isActive;
    }), powerups.end());
}
void cleanVector(std::vector<Asteroid> &asteroids){
    asteroids.erase(std::remove_if(asteroids.begin(), asteroids.end(), [](const Asteroid& aste) {
        return !aste.isActive;
    }), asteroids.end());
}

