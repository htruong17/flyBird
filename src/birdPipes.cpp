#include <iostream>
#include <SFML/Graphics.hpp>
#include "birdClass.hpp"
using namespace std;
int main()
{
    
    // Create Bird Constructor
    myBird bird(180.f);
    
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    window.setKeyRepeatEnabled(false);
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            else if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Up)
                //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    cout << "Up" << endl;
                    bird.move(-10);
                }
                else if (event.key.code == sf::Keyboard::Down){
                    bird.move(10);
                }
            }
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        
    sf::CircleShape circle(10.f);

// set the shape color to blue
circle.setFillColor(sf::Color(255,0,0));
//circle.setOutlineThickness(10.f);
        circle.setPosition(390.f, bird.posY);
window.draw(circle);
        
    // end the current frame
        window.display();
    
    }
   
    
    return 0;
}
