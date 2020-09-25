#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "birdClass.hpp"
#include "pipeClass.hpp"
using namespace std;
int main()
{
    srand(time(nullptr));
    
    // Create Bird Constructor
    vector<myPipe> myPipes;
    myPipes.push_back(myPipe(1500.f));
    myPipes.push_back(myPipe(1800.f));
    myPipes.push_back(myPipe(2100.f));
    myPipes.push_back(myPipe(2400.f));
    
    myBird bird(350.f, 180.f);
    
    bool collision = false;
    bool pause = false;
    sf::CircleShape circle(10.f);
    myPipes[0].create();
    myPipes[1].create();
    myPipes[2].create();
    myPipes[3].create();
    
    //random select background and sound
    string randomBG = to_string(rand()%5 +1) + ".png";
    string randomS = to_string(rand()%5 +1) + ".wav";
    //cout << randomBG << endl;
    
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Playground");
    
    //Create background
    sf::Texture bgTex;
    bgTex.loadFromFile(randomBG);
    sf::Sprite bgSprite;
    bgSprite.setTexture(bgTex);
    bgSprite.setScale(float (window.getSize().x)/(bgTex.getSize().x), float (window.getSize().y)/(bgTex.getSize().y));
    
    //Create sound
    sf::SoundBuffer buffer;
    buffer.loadFromFile(randomS);
    sf::Sound birdSound;
    birdSound.setBuffer(buffer);
    
    //Create point
    int score = 0;
    sf::Text text;
    text.setString(to_string(score));
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Red);
    text.setPosition(350.f, 180.f);
    
     
    // create the window
    //sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Playground");
  
    //window.setFramerateLimit(60);
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
                    birdSound.play();
                }
                else if (event.key.code == sf::Keyboard::Space){
                cout << "Pause" << endl;
                    pause = !pause;
                }
            }
            
        }

        // clear the window with black color
        window.clear();
        window.draw(bgSprite);
    

// set the shape color to blue
circle.setFillColor(sf::Color(255,0,0));
        if (collision){
            myPipes[1].recTOP.setFillColor(sf::Color(255,255,0));
            myPipes[1].recBOT.setFillColor(sf::Color(255,255,0));
        } else {
            myPipes[0].recTOP.setFillColor(sf::Color(70,130,180));
            myPipes[0].recBOT.setFillColor(sf::Color(70,130,180));
            myPipes[1].recTOP.setFillColor(sf::Color(250,0,0));
            myPipes[1].recBOT.setFillColor(sf::Color(250,0,0));
            myPipes[2].recTOP.setFillColor(sf::Color(50,205,50));
            myPipes[2].recBOT.setFillColor(sf::Color(50,205,50));
            myPipes[3].recTOP.setFillColor(sf::Color(153,50,204));
            myPipes[3].recBOT.setFillColor(sf::Color(153,50,204));
        }
//circle.setOutlineThickness(10.f);
        circle.setPosition(390.f, bird.posY);
        myPipes[0].position();
        myPipes[1].position();
        myPipes[2].position();
        myPipes[3].position();
        myPipes[0].Draw(window);
        myPipes[1].Draw(window);
        myPipes[2].Draw(window);
        myPipes[3].Draw(window);
        window.draw(circle);
    
    // end the current frame
        window.display();
    
        if(circle.getGlobalBounds().intersects(myPipes[0].recTOP.getGlobalBounds()) || circle.getGlobalBounds().intersects(myPipes[0].recBOT.getGlobalBounds()) || circle.getGlobalBounds().intersects(myPipes[1].recTOP.getGlobalBounds()) || circle.getGlobalBounds().intersects(myPipes[1].recBOT.getGlobalBounds())){
            collision = true;
        } else {
            collision = false;
        }
        
       
        if(!pause){
            bird.moveY(-0.0008); //Update circle position
            myPipes[0].move(-.2);
            myPipes[1].move(-.2);
            myPipes[2].move(-.2);
            myPipes[3].move(-.2);
        }
        
        
        if(myPipes[0].posX < -100){
            
            myPipes.push_back(myPipe(myPipes[3].posX+300.f));
            myPipes[4].create();
            myPipes.erase(myPipes.begin());
            score += 1;
            
           // myPipes[0] = myPipe(myPipes[3].posX+300.f);
           //myPipes[0].create();
        }
        
        if(collision) {
            bird.posY = 580;
//            cout << myPipes[0].posX << endl;
//            cout << bird.posX << endl;
            pause = !pause;
            
        }
        window.draw(text);
        
//        } else if(myPipes[1].posX < -100){
//            myPipes[1] = myPipe(myPipes[0].posX+300.f);
//            myPipes[1].create();
//        } else if(myPipes[2].posX < -100){
//            myPipes[2] = myPipe(myPipes[1].posX+300.f);
//            myPipes[2].create();
//        } else if(myPipes[3].posX < -100){
//            myPipes[3] = myPipe(myPipes[2].posX+300.f);
//            myPipes[3].create();
//        }
    }
   
        
   
    return 0;
}
