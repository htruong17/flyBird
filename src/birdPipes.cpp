#include <iostream>
#include <SFML/Graphics.hpp>
#include "birdClass.hpp"
#include "pipeClass.hpp"
using namespace std;
int main()
{
    
    // Create Bird Constructor
    myBird bird(390.f, 180.f);
    myPipe pipe(400.f,-100.f);
    
    bool collision = true;
    bool pause = false;
    sf::CircleShape circle(10.f);
    pipe.create();
    sf::RectangleShape rectangle2top(sf::Vector2f(50,400));
    sf::RectangleShape rectangle2bot(sf::Vector2f(50,400));
    sf::RectangleShape rectangle3top(sf::Vector2f(50,400));
    sf::RectangleShape rectangle3bot(sf::Vector2f(50,400));
    
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
//        if (collision){
//            rectangle1top.setFillColor(sf::Color(255,255,0));
//        } else {
//            rectangle1top.setFillColor(sf::Color(70,130,180));
//        }
//circle.setOutlineThickness(10.f);
        circle.setPosition(390.f, bird.posY);
    
        rectangle2top.setPosition(300.f, 300.f);
        rectangle2bot.setPosition(300.f, -300.f);
        rectangle3top.setPosition(550.f, 400.f);
        rectangle3bot.setPosition(550.f, -200.f);
        pipe.Draw(window);
        window.draw(rectangle2top);
        window.draw(rectangle2bot);
        window.draw(rectangle3top);
        window.draw(rectangle3bot);
        window.draw(circle);
    
    // end the current frame
        window.display();
    
//        if(circle.getGlobalBounds().intersects(rectangle1top.getGlobalBounds())){
//                collision = true;
//            } else {
//                collision = false;
//            }
        if(!pause){
            bird.moveY(-0.0008); //Update circle position
            //pipe.move(-.05);
            //bird.MoveX(-0.18);
        }
    }
   
        
   
    return 0;
}
