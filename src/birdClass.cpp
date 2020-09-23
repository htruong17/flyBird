//
//  birdClass.cpp
//  flyBird
//
//  Created by Harold Truong on 9/22/20.
//

#include "birdClass.hpp"

myBird::myBird(float x, float y){
    posX = x;
    posY = y;
    velocity = 0;
}

void myBird::jump(const float& speed){
    velocity = -speed;
}
void myBird::moveY(const float& accel){ // Drop or Gravity
    velocity -= accel;
    posY += velocity;
    if (posY > 580){
        posY = 580;
        velocity = 0;
    } else if (posY < 0){
        posY = 0;
        velocity = 0;
    }
}

void myBird::MoveX(const float& v){
    posX += v;
}

