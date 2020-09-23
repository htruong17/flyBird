#include <iostream>
#include <SFML/Graphics.hpp>
#include "birdClass.hpp"
using namespace std;
int main()
{
    
    // Create Bird Constructor
    myBird bird(390.f, 180.f);
    bool collision = true;
    bool pause = false;
    sf::CircleShape circle(10.f);
    sf::RectangleShape rectangle1(sf::Vector2f(50,400));
    sf::RectangleShape rectangle2(sf::Vector2f(50,400));
    sf::RectangleShape rectangle3(sf::Vector2f(50,400));
    sf::RectangleShape rectangle4(sf::Vector2f(50,400));
    
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
                    bird.jump(.45);
                }
                else if (event.key.code == sf::Keyboard::Space){
                cout << "Pause" << endl;
                    pause = !pause;
                }
            }
            
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

    

// set the shape color to blue
circle.setFillColor(sf::Color(255,0,0));
        if (collision){
            rectangle1.setFillColor(sf::Color(255,255,0));
        } else {
            rectangle1.setFillColor(sf::Color(70,130,180));
        }
//circle.setOutlineThickness(10.f);
        circle.setPosition(390.f, bird.posY);
        rectangle1.setPosition(10 + bird.posX, 500.f);
        rectangle2.setPosition(10 + bird.posX, -100.f);
        rectangle3.setPosition(310.f + bird.posX, 300.f);
        rectangle4.setPosition(310.f + bird.posX, -300.f);
        
        window.draw(rectangle1);
        window.draw(rectangle2);
        window.draw(rectangle3);
        window.draw(rectangle4);
        window.draw(circle);
        
    // end the current frame
        window.display();
    
        if(circle.getGlobalBounds().intersects(rectangle1.getGlobalBounds())){
                collision = true;
            } else {
                collision = false;
            }
        if(!pause){
            bird.moveY(-0.0008); //Update circle position
            bird.MoveX(-0.19);
        }
    }
   
        
   
    return 0;
}
