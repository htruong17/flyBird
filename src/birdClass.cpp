//
//  birdClass.cpp
//  flyBird
//
//  Created by Harold Truong on 9/22/20.
//

#include "birdClass.hpp"

myBird::myBird(float y){
    posY = y;
}

void myBird::move(const float y){
    posY += y;
}
