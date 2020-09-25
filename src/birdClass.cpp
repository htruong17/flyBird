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
    sf::CircleShape circle(40.f);
    birdie = circle;
    
}

void myBird::jump(const float& speed){
    velocity = -speed;
}
void myBird::moveY(const float& accel){ // Drop or Gravity
    velocity -= accel;
    posY += velocity;
    if (posY > 1120){
        posY = 1120;
        velocity = 0;
    } else if (posY < 0){
        posY = 0;
        velocity = 0;
    }
}

void myBird::position(){
    birdie.setPosition(posX, posY);
}

void myBird::color(int a, int b, int c) {
    birdie.setFillColor(sf::Color(a, b, c));
}

void myBird::Draw(sf::RenderWindow& window){
    window.draw(birdie);
}
