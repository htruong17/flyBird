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
#include <SFML/Graphics.hpp>

class myBird{
    
public:
    float posX;
    float posY;
    float velocity;
    sf::CircleShape birdie;
    
    myBird(float x, float y);
    
    // Declare method to move bird vertically
    void moveY(const float& accel);
    void jump(const float& speed);
    void position();
    void color(int a, int b, int c);
    void Draw(sf::RenderWindow& window);
};

#endif /* birdClass_hpp */
