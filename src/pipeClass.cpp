//
//  pipeClass.cpp
//  flyBird
//
//  Created by Harold Truong on 9/22/20.
//
#include <SFML/Graphics.hpp>
#include "pipeClass.hpp"

myPipe::myPipe(int x, int y){
    posX = x;
    posY = y;
}

void myPipe::create(){
    sf::RectangleShape rectangleTOP(sf::Vector2f(50,400));
    sf::RectangleShape rectangleBOT(sf::Vector2f(50,400));
    recTOP = rectangleTOP;
    recBOT = rectangleBOT;
    recTOP.setPosition(posX, posY);
    recBOT.setPosition(posX, posY+600);
}

void myPipe::move(const float& velocity){
    posX += velocity;
    recTOP.setPosition(posX, posY);
    recBOT.setPosition(posX, posY+600);
}

void myPipe::Draw(sf::RenderWindow& window){
    window.draw(recTOP);
    window.draw(recBOT);
}


