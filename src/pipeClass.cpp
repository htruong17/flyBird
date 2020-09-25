//
//  pipeClass.cpp
//  flyBird
//
//  Created by Harold Truong on 9/22/20.
//
#include <SFML/Graphics.hpp>
#include "pipeClass.hpp"

// Pip constructor
myPipe::myPipe(float x){
    posX = x;
    posY = -(rand()%300) - 50;
}

void myPipe::create(){
    sf::RectangleShape rectangleTOP(sf::Vector2f(100,800));
    sf::RectangleShape rectangleBOT(sf::Vector2f(100,800));
    recTOP = rectangleTOP;
    recBOT = rectangleBOT;
}

void myPipe::position(){
    recTOP.setPosition(posX, posY);
    recBOT.setPosition(posX, posY+1100);
}

void myPipe::move(const float& velocity){
    posX += velocity;
}

void myPipe::Draw(sf::RenderWindow& window){
    window.draw(recTOP);
    window.draw(recBOT);
}


