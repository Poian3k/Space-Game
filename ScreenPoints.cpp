#include "ScreenPoints.h"
int bigSide = 30;
int smallSide = 6;
//the numbers functions generates the correct segments and render them
void Zero(SDL_Renderer* renderer, int xBase, int yBase){
    SDL_Rect top { xBase , yBase , bigSide , smallSide};
    SDL_Rect bottom { xBase , yBase + 60  , bigSide , smallSide};
    SDL_Rect topRight { xBase + 30 - smallSide , yBase , smallSide, bigSide};
    SDL_Rect bottomLeft { xBase , yBase + 30  , smallSide, bigSide};
    SDL_Rect topLeft { xBase , yBase , smallSide, bigSide};
    SDL_Rect bottomRight { xBase + 30 - smallSide , yBase + 30  , smallSide, bigSide};

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &top);
    SDL_RenderFillRect(renderer, &bottom);
    SDL_RenderFillRect(renderer, &topRight);
    SDL_RenderFillRect(renderer, &topLeft);
    SDL_RenderFillRect(renderer, &bottomLeft);
    SDL_RenderFillRect(renderer, &bottomRight);
}

void One(SDL_Renderer* renderer, int xBase, int yBase){
    SDL_Rect topRight { xBase + 30 - smallSide, yBase, smallSide, bigSide};
    SDL_Rect bottomRight { xBase + 30 - smallSide, yBase + 30, smallSide, bigSide};
    
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &topRight);
    SDL_RenderFillRect(renderer, &bottomRight);
}

void Two(SDL_Renderer* renderer, int xBase, int yBase){
    SDL_Rect top { xBase , yBase , bigSide , smallSide};
    SDL_Rect mid { xBase , yBase + 30 , bigSide , smallSide};
    SDL_Rect bottom { xBase , yBase + 60  , bigSide , smallSide};
    SDL_Rect topRight { xBase + 30 - smallSide, yBase, smallSide, bigSide};
    SDL_Rect bottomLeft { xBase , yBase + 30  , smallSide, bigSide};

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &top);
    SDL_RenderFillRect(renderer, &mid);
    SDL_RenderFillRect(renderer, &bottom);
    SDL_RenderFillRect(renderer, &topRight);
    SDL_RenderFillRect(renderer, &bottomLeft);
}

void Three(SDL_Renderer* renderer, int xBase, int yBase){
    SDL_Rect top { xBase , yBase , bigSide , smallSide};
    SDL_Rect mid { xBase , yBase + 30 , bigSide , smallSide};
    SDL_Rect bottom { xBase , yBase + 60  , bigSide , smallSide};
    SDL_Rect topRight { xBase + 30 - smallSide, yBase, smallSide, bigSide};
    SDL_Rect bottomRight { xBase + 30 - 6 , yBase + 30  , smallSide, bigSide};

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &top);
    SDL_RenderFillRect(renderer, &mid);
    SDL_RenderFillRect(renderer, &bottom);
    SDL_RenderFillRect(renderer, &topRight);
    SDL_RenderFillRect(renderer, &bottomRight);
}
void Four(SDL_Renderer* renderer, int xBase, int yBase){
    SDL_Rect mid { xBase , yBase + 30 , bigSide , smallSide};
    SDL_Rect topRight { xBase + 30 - smallSide , yBase , smallSide, bigSide};
    SDL_Rect topLeft { xBase , yBase , smallSide, bigSide};
    SDL_Rect bottomRight { xBase + 30 - smallSide , yBase + 30  , smallSide, bigSide};

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &mid);
    SDL_RenderFillRect(renderer, &topRight);
    SDL_RenderFillRect(renderer, &topLeft);
    SDL_RenderFillRect(renderer, &bottomRight);
}

void Five(SDL_Renderer* renderer, int xBase, int yBase){
    SDL_Rect top { xBase , yBase , bigSide , smallSide};
    SDL_Rect mid { xBase , yBase + 30 , bigSide , smallSide};
    SDL_Rect bottom { xBase , yBase + 60  , bigSide , smallSide};
    SDL_Rect bottomRight { xBase + 30 - smallSide , yBase + 30 , smallSide, bigSide};
    SDL_Rect topLeft { xBase , yBase , smallSide, bigSide};

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &top);
    SDL_RenderFillRect(renderer, &mid);
    SDL_RenderFillRect(renderer, &bottom);
    SDL_RenderFillRect(renderer, &topLeft);
    SDL_RenderFillRect(renderer, &bottomRight);
}

void Six(SDL_Renderer* renderer, int xBase, int yBase){
    SDL_Rect top { xBase , yBase , bigSide , smallSide};
    SDL_Rect mid { xBase , yBase + 30 , bigSide , smallSide};
    SDL_Rect bottom { xBase , yBase + 60  , bigSide , smallSide};
    SDL_Rect bottomLeft { xBase , yBase + 30  , smallSide, bigSide};
    SDL_Rect topLeft { xBase , yBase , smallSide, bigSide};
    SDL_Rect bottomRight { xBase + 30 - smallSide , yBase + 30  , smallSide, bigSide};

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &top);
    SDL_RenderFillRect(renderer, &mid);
    SDL_RenderFillRect(renderer, &bottom);
    SDL_RenderFillRect(renderer, &topLeft);
    SDL_RenderFillRect(renderer, &bottomRight);
    SDL_RenderFillRect(renderer, &bottomLeft);
}

void Seven(SDL_Renderer* renderer, int xBase, int yBase){
    SDL_Rect top { xBase , yBase , bigSide , smallSide};
    SDL_Rect topRight { xBase + 30 - smallSide , yBase , smallSide, bigSide};
    SDL_Rect bottomRight { xBase + 30 - smallSide , yBase + 30  , smallSide, bigSide};

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &top);
    SDL_RenderFillRect(renderer, &topRight);
    SDL_RenderFillRect(renderer, &bottomRight);
}

void Eight(SDL_Renderer* renderer, int xBase, int yBase){
    SDL_Rect top { xBase , yBase , bigSide , smallSide};
    SDL_Rect mid { xBase , yBase + 30 , bigSide , smallSide};
    SDL_Rect bottom { xBase , yBase + 60  , bigSide , smallSide};
    SDL_Rect topRight { xBase + 30 - smallSide , yBase , smallSide, bigSide};
    SDL_Rect bottomLeft { xBase , yBase + 30  , smallSide, bigSide};
    SDL_Rect topLeft { xBase , yBase , smallSide, bigSide};
    SDL_Rect bottomRight { xBase + 30 - smallSide , yBase + 30  , smallSide, bigSide};

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &top);
    SDL_RenderFillRect(renderer, &mid);
    SDL_RenderFillRect(renderer, &bottom);
    SDL_RenderFillRect(renderer, &topRight);
    SDL_RenderFillRect(renderer, &topLeft);
    SDL_RenderFillRect(renderer, &bottomLeft);
    SDL_RenderFillRect(renderer, &bottomRight);
}

void Nine(SDL_Renderer* renderer, int xBase, int yBase){
    SDL_Rect top { xBase , yBase , bigSide , smallSide};
    SDL_Rect mid { xBase , yBase + 30 , bigSide , smallSide};
    SDL_Rect bottom { xBase , yBase + 60  , bigSide , smallSide};
    SDL_Rect topRight { xBase + 30 - smallSide , yBase , smallSide, bigSide};
    SDL_Rect topLeft { xBase , yBase , smallSide, bigSide};
    SDL_Rect bottomRight { xBase + 30 - smallSide , yBase + 30  , smallSide, bigSide};

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &top);
    SDL_RenderFillRect(renderer, &mid);
    SDL_RenderFillRect(renderer, &bottom);
    SDL_RenderFillRect(renderer, &bottomRight);
    SDL_RenderFillRect(renderer, &topLeft);
    SDL_RenderFillRect(renderer, &topRight);
}



void createNum(int xBase, int yBase, int points, SDL_Renderer* renderer){
    std::vector<int> nums; //array to contain all the digits
    if(points > 0){ // to ensure errors int the for loop
        while(points > 0){//store the digits in the vecto rin reverse order
            nums.push_back((points % 10));
            points = (points/10);
        }
    }else{
        nums.push_back(0); // limit case
    }
    
    for (int i = (nums.size()-1); i >= 0 ; i--) {//print the digits ( in th eright order)
        switch (nums[i]) {
            case 0:
                Zero(renderer, xBase, yBase);
                break;
            case 1:
                One(renderer, xBase, yBase);
                break;
            case 2:
                Two(renderer, xBase, yBase);
                break;
            case 3:
                Three(renderer, xBase, yBase);
                break;
            case 4:
                Four(renderer, xBase, yBase);
                break;
            case 5:
                Five(renderer, xBase, yBase);
                break;
            case 6:
                Six(renderer, xBase, yBase);
                break;
            case 7:
                Seven(renderer, xBase, yBase);
                break;
            case 8:
                Eight(renderer, xBase, yBase);
                break;
            case 9:
                Nine(renderer, xBase, yBase);
                break;
        }
        xBase += 50;
    }    
}
