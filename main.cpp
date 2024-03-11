#include <SDL2/SDL.h>
#include <iostream>
#include <ctime>
#include <vector>
#include "Hitbox.h"
#include "Collision.h"
#include "Game.h"
#include "Asteroids.h"
#include "ScreenPoints.h"#include <SDL2/SDL.h>
#include <iostream>
#include <ctime>
#include <vector>
#include "Hitbox.h"
#include "Collision.h"
#include "Game.h"
#include "Asteroids.h"
#include "ScreenPoints.h"

int main(int argc, char* argv[]) {
    
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    int WIDTH = 1200, HEIGHT = 900;

    // Create a window
    SDL_Window* window = SDL_CreateWindow("SpaceShip Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);

    // Create a renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    // Create an instance of the Ship class
    Ship ship(400, 500);

    std::vector<Projectile> projectiles;
    std::vector<EnemyShip> enemies;
    std::vector<Powerup> powerups;
    std::vector<Asteroid> asteroids;

    int count = 0, points = 0, level = 1, lifelimit = 5, powlev = 1, difficulty = 1;//powlev is needed to ensure to create infinite powerups if the player doesn't score points when it is at  n % 10
    bool quit = false;
    int xBase = 70, yBase = 30;//coordinates for points display

    const Uint8* keyStates = SDL_GetKeyboardState(NULL);
    SDL_Event event;
  
    while (!quit) {
    
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            } else if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_RESIZED) {
                // Update WIDTH and HEIGHT when the window is resized
                WIDTH = event.window.data1;
                HEIGHT = event.window.data2;
            }
        }

        count++;//to add delay for some objects
        
         
        // Clear the renderer(background black)
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Move the ship
        ship.Move(HEIGHT, WIDTH);

        // Render the ship
        ship.Render(renderer, level);

        ship.Fire(projectiles, level);

        killEnemy(projectiles, enemies, renderer, points);

        cleanVector(projectiles);
        cleanVector(enemies);
        cleanVector(powerups);
        cleanVector(asteroids);


        levelUp(ship, powerups, count, HEIGHT, level, renderer);
        // Render active enemy ships
        for ( auto& enemy : enemies) {
            if (enemy.isActive) {
                lifelimit -= enemy.Move(HEIGHT);
                enemy.Render(renderer);
            }
        }

    
        // Create a new enemy ship every 1000 iterations
        EnemyShip::Create(enemies, WIDTH, count, difficulty);

        //create the powerups
        Powerup::Create(powerups, WIDTH, points, powlev);
        
        Asteroid::Create(asteroids, WIDTH, HEIGHT, count, difficulty, points);

        AsteroidInpact(ship, asteroids, count, WIDTH, HEIGHT, lifelimit, renderer);

        lifeCount(renderer, lifelimit, quit, WIDTH);
        
        if(keyStates[SDL_SCANCODE_X]) {//pause key
            pause(event, renderer, keyStates, quit);//function of pause
        }
        
        createNum(xBase, yBase, points, renderer); //function to create the digits of the points and diplay them
       

        // Update the screen
        SDL_RenderPresent(renderer);

    } 
    // Clean up resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    std::cout<<points;

    return 0;
}


int main(int argc, char* argv[]) {
    
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    int WIDTH = 1200, HEIGHT = 900;

    // Create a window
    SDL_Window* window = SDL_CreateWindow("Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0);

    // Create a renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    // Create an instance of the Ship class
    Ship ship(400, 500);

    std::vector<Projectile> projectiles;
    std::vector<EnemyShip> enemies;
    std::vector<Powerup> powerups;
    std::vector<Asteroid> asteroids;

    int count = 0, points = 0,level = 1,lifelimit = 5, powlev = 1, difficulty = 1;//powlev is needed to ensure to create infinite powerups if the player doesn't score points when it is at  n % 10
    bool quit = false;
    int xBase = 70, yBase = 30;//coordinates for points display

    const Uint8* keyStates = SDL_GetKeyboardState(NULL);
    SDL_Event event;
  
    while (!quit) {
    
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        count++;//to add delay for some objects
        
        
        // Clear the renderer(background black)
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Move the ship
        ship.Move(HEIGHT, WIDTH);

        // Render the ship
        ship.Render(renderer, level);

        ship.Fire(projectiles, level);

        killEnemy(projectiles, enemies, renderer, points);

        cleanVector(projectiles);
        cleanVector(enemies);
        cleanVector(powerups);
        cleanVector(asteroids);  

        levelUp(ship, powerups, count, HEIGHT, level, renderer);
        // Render active enemy ships
        for ( auto& enemy : enemies) {
            if (enemy.isActive) {
                lifelimit -= enemy.Move(HEIGHT);
                enemy.Render(renderer);
            }
        }

    
        // Create a new enemy ship every 1000 iterations
        EnemyShip::Create(enemies, WIDTH, count, difficulty);

        //create the powerups
        Powerup::Create(powerups, WIDTH, points, powlev);
        
        Asteroid::Create(asteroids, WIDTH, HEIGHT, count, difficulty, points);

        AsteroidInpact(ship, asteroids, count, WIDTH, HEIGHT, lifelimit, renderer);

        lifeCount(renderer, lifelimit, quit, WIDTH);
        
        if(keyStates[SDL_SCANCODE_X]) {//pause function
            pause(event, renderer, keyStates, quit);//function of pause
        }
        
        createNum(xBase, yBase, points, renderer); //function to create the digits of the points and diplay them
       

        // Update the screen
        SDL_RenderPresent(renderer);

    } 
    // Clean up resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    std::cout<<points;

    return 0;
}
