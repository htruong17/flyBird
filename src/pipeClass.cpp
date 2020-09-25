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
    posY = (-(rand()%8) - 2) * 100;
    sf::RectangleShape rectangleTOP(sf::Vector2f(200, 1000));
    sf::RectangleShape rectangleBOT(sf::Vector2f(200, 1000));
    recTOP = rectangleTOP;
    recBOT = rectangleBOT;
}

void myPipe::position(){
    recTOP.setPosition(posX, posY);
    recBOT.setPosition(posX, posY + 1300);
}

void myPipe::move(const float& velocity){
    posX += velocity;
}

void myPipe::Draw(sf::RenderWindow& window){
    window.draw(recTOP);
    window.draw(recBOT);
}


