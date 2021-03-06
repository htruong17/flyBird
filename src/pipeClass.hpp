//
//  pipeClass.hpp
//  flyBird
//
//  Created by Harold Truong on 9/22/20.
//

#ifndef pipeClass_hpp
#define pipeClass_hpp
#include <SFML/Graphics.hpp> 
#include <stdio.h>

class myPipe{
    
public:
    float posX;
    float posY;
    sf::RectangleShape recTOP;
    sf::RectangleShape recBOT;
    
    myPipe(float x);
    
    // Declare method to move pip horizontally
    void position();
    void move(const float& accel);
    void Draw(sf::RenderWindow& window);
    void color(int a, int b, int c);
               
};

#endif /* pipeClass_hpp */
