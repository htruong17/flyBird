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
    velocity = speed;
}
void myBird::moveY(const float& accel){
    velocity += accel;
    posY += velocity;
}


