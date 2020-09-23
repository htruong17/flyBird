//
//  pipeClass.hpp
//  flyBird
//
//  Created by Harold Truong on 9/22/20.
//

#ifndef pipeClass_hpp
#define pipeClass_hpp

#include <stdio.h>

class myPipe{
    
public:
    int posX;
    int posY;
    sf::RectangleShape recTOP;
    sf::RectangleShape recBOT;
    
    myPipe(int x, int y);
    
    // Declare method to move pip horizontally
    void create();
    void move(const float& accel);
    void Draw(sf::RenderWindow& window);
    
};

#endif /* pipeClass_hpp */
