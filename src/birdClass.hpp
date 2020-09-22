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
    float posY;
    myBird(float y);
    
    // Declare method to move bird vertically
    void move(const float y);
};

#endif /* birdClass_hpp */
