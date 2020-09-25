#include "birdClass.hpp"
#include "pipeClass.hpp"
#include <SFML/Audio.hpp>
using namespace std;
int main()
{
    srand(time(nullptr));
    
    bool pause = false;
    bool firstPipe = false;
    bool gameover = false;
    bool start = false;
    
    int index = 0;
    //Create Bird Constructor
    vector<myPipe> myPipes;
    myPipes.push_back(myPipe(2100.f));
    myPipes.push_back(myPipe(2900.f));
    myPipes.push_back(myPipe(3700.f));
    myPipes.push_back(myPipe(4500.f));
    
    myBird bird(760.f, 600.f);
    
    sf::CircleShape circle(40.f);
    
    //Random select background and sound
    string randomBG = to_string(rand()%3 +1) + ".png";
    string randomS = to_string(rand()%3 +1) + ".wav";
    
    //Create the window
    sf::RenderWindow window(sf::VideoMode(1600, 1200), "SFML Playground");
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);
    
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
    birdSound.setVolume(20);

    //Create score
    int score = 0;
    sf::Font font;
    font.loadFromFile("arial.ttf");
    sf::Text text1, text2;
    text1.setFont(font);
    text1.setCharacterSize(100);
    text1.setFillColor(sf::Color::White);
    text1.setStyle(sf::Text::Bold);
    text1.setPosition(760.f, 100.f);

    text2.setFont(font);
    text2.setString("GAME OVER");
    text2.setCharacterSize(100);
    text2.setFillColor(sf::Color::Yellow);
    text2.setOutlineColor(sf::Color::Black);
    text2.setOutlineThickness(5);
    text2.setStyle(sf::Text::Bold);
    text2.setPosition(500.f, 400.f);
    
    //Run the program as long as the window is open
    while (window.isOpen())
    {
        //Check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            //"close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            else if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Up)
                {
                    if(!gameover){
                        bird.jump(19);
                        birdSound.play();
                        start = true;
                    } else{
                        myPipes[0] = myPipe(2100.f);
                        myPipes[1] = myPipe(2900.f);
                        myPipes[2] = myPipe(3700.f);
                        myPipes[3] = myPipe(4500.f);
                        bird = myBird(760.f, 600.f);
                        gameover = false;
                        start = false;
                        firstPipe = false;
                        pause = false;
                        index = 0;
                        score = 0; 
                    }
                } else if (event.key.code == sf::Keyboard::Space){
                cout << "Pause" << endl;
                    if(start){
                        pause = !pause;
                    }
                }
            }
            
        }

        //Clear the window with black color
        window.clear();
        window.draw(bgSprite);
    

        //Set the shape color to blue
        circle.setFillColor(sf::Color(255,0,0));
        for (int i = 0; i < myPipes.size(); i++) {
            if (randomBG == "1.png") {
                myPipes[i].color(0, 153, 0);
            }
            else if (randomBG == "2.png") {
                myPipes[i].color(192, 192, 192);
            }
            else if (randomBG == "3.png") {
                myPipes[i].color(204, 102, 0);
            }
        }
      
        
        circle.setPosition(760.f, bird.posY);
        
        for (int i = 0; i < myPipes.size(); i++) {
            myPipes[i].position();
            myPipes[i].Draw(window);
        }
        
        window.draw(circle);
    
        //End the current frame
        
        if(circle.getGlobalBounds().intersects(myPipes[score%4].recTOP.getGlobalBounds()) || circle.getGlobalBounds().intersects(myPipes[score%4].recBOT.getGlobalBounds())){
                gameover = true;
            }
        
        if (bird.posY >= 1110){
            gameover = true;
        }
        
        if (!start){
            if (bird.posY > 590.f){
                bird.moveY(1);
            } else if (bird.posY <= 590.f){
                bird.moveY(-1);
            }
        } else if(gameover){
            bird.moveY(-1);
            text1.setString(to_string(score));
            window.draw(text1);
            window.draw(text2);
        } else if(!pause){
            bird.moveY(-1); //Update circle position
            for (int i = 0; i < myPipes.size(); i++) {
                myPipes[i].move(-7);
            }

            text1.setString(to_string(score));
            window.draw(text1);
        }

        if(myPipes[index%4].posX < -600){
            firstPipe = true;
            myPipes[index%4] = myPipe(myPipes[(3 + index)%4].posX + 800.f);
            index++;
        }
        
        if(myPipes[score%4].posX < 495){
            score++;
        }
        window.display();
    }
  
    return 0;
}
