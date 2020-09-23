//
//  birdClass.hpp
//  flyBird
//
//  Created by Harold Truong on 9/22/20.
//

#ifndef birdClass_hpp
#define birdClass_hpp

#include <stdio.h>
#include <iostream>

class myBird{
    
public:
    float posX;
    float posY;
    float velocity;
    
    myBird(float x, float y);
    
    // Declare method to move bird vertically
    void moveY(const float& accel);
    void jump(const float& speed);
};

#endif /* birdClass_hpp */
