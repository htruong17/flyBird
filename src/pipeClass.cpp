//
//  pipeClass.cpp
//  flyBird
//
//  Created by Harold Truong on 9/22/20.
//
#include <SFML/Graphics.hpp>
#include "pipeClass.hpp"

myPipe::myPipe(float x, float y){
    
    posX = x;
    posY = y;
}

void myPipe::create(){
    sf::RectangleShape rectangleTOP(sf::Vector2f(50,400));
    sf::RectangleShape rectangleBOT(sf::Vector2f(50,400));
    recTOP = rectangleTOP;
    recBOT = rectangleBOT;
}

void myPipe::position(){
    recTOP.setPosition(posX, posY);
    recBOT.setPosition(posX, posY+600);
}

void myPipe::move(const float& velocity){
    posX += velocity;
}

void myPipe::Draw(sf::RenderWindow& window){
    window.draw(recTOP);
    window.draw(recBOT);
}


