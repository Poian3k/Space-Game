#ifndef COLLISION_H
#define COLLISION_H

#include <SDL2/SDL.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Ship.h" 
#include "Enemies.h"
#include "Powerups.h"
#include "hitbox.h"
#include "Asteroids.h"

void killEnemy(std::vector<Projectile> &projectiles, std::vector<EnemyShip> &enemies, SDL_Renderer* renderer, int &points);//move a projectile and check the collision between a projectile and an enemy
void levelUp(const Ship &ship, std::vector<Powerup> &powerups, int count, int HEIGHT, int &level, SDL_Renderer* renderer);
void AsteroidInpact(Ship &ship, std::vector<Asteroid> &asteroids, int count, int WIDTH, int HEIGTH, int &lifelimit, SDL_Renderer* renderer);

void cleanVector(std::vector<EnemyShip> &enemies);// Remove inactive enemies from the vector
void cleanVector(std::vector<Projectile> &projectiles);// Remove inactive projectiles from the vector
void cleanVector(std::vector<Powerup> &powerups);
void cleanVector(std::vector<Asteroid> &asteroids);


#endif //COLLISION_H