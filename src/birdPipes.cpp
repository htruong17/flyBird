#include "birdClass.hpp"
#include "pipeClass.hpp"
#include <SFML/Audio.hpp>
using namespace std;
int main()
{
    srand(time(nullptr));
    
    bool pause = false;
    bool gameover = false;
    bool start = false; //Gameplay hasn't started. Bird in hover phase
    int index = 0; //Index of the pipe for infinite looping
    
    //Create Pipe Constructor into vector
    vector<myPipe> myPipes;
    myPipes.push_back(myPipe(2100.f));
    myPipes.push_back(myPipe(2900.f));
    myPipes.push_back(myPipe(3700.f));
    myPipes.push_back(myPipe(4500.f));
    
    //Constructing bird
    myBird bird(760.f, 600.f);
    
    //Random select background and sound
    string randomBG = to_string(rand()%3 +1) + ".png";
    string randomS = to_string(rand()%3 +1) + ".wav";
    
    //Create the window
    sf::RenderWindow window(sf::VideoMode(1600, 1200), "SFML Playground");
    
    //Fixed timerate and unabling keyboard repeat
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

    //Create score display
    int score = 0;
    sf::Font font;
    font.loadFromFile("arial.ttf");
    sf::Text text1, text2;
    text1.setFont(font);
    text1.setCharacterSize(100);
    text1.setFillColor(sf::Color::White);
    text1.setStyle(sf::Text::Bold);
    text1.setPosition(760.f, 100.f);

    //Create game over message
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
                if(event.key.code == sf::Keyboard::Up) // When pressing the up key
                {
                    //If you're still alive
                    if(!gameover){
                        bird.jump(19); //Makes bird fly or jump
                        start = true; //Kicks bird out of floating phase when first initializing game
                        if (!pause){
                            birdSound.play(); //Plays sound when flying/jumping
                        }
                    } else{ //Press up when dead to restart game
                        myPipes[0] = myPipe(2100.f);
                        myPipes[1] = myPipe(2900.f);
                        myPipes[2] = myPipe(3700.f);
                        myPipes[3] = myPipe(4500.f);
                        bird = myBird(760.f, 600.f);
                        gameover = false;
                        start = false;
                        pause = false;
                        index = 0;
                        score = 0; 
                    }
                } else if (event.key.code == sf::Keyboard::Space){ // When pressing the space key
                    if(start){
                        pause = !pause; //Turns pause on and off
                    }
                }
            }
        }

        //Clear the window and draws background
        window.clear();
        window.draw(bgSprite);
    

        //Set the bird color and pipe colors accordingly to background loaded
        bird.color(255, 0, 0);
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
      
        // Drawing and updating position of bird and pipes
        bird.position();
        bird.Draw(window);
        for (int i = 0; i < myPipes.size(); i++) {
            myPipes[i].position();
            myPipes[i].Draw(window);
        }
        
        //Checking for collision between objects
        if(bird.birdie.getGlobalBounds().intersects(myPipes[score%4].recTOP.getGlobalBounds()) || bird.birdie.getGlobalBounds().intersects(myPipes[score%4].recBOT.getGlobalBounds())){
                gameover = true; //Ends game if collision detected
            }
        
        //Game over if bird touches the ground
        if (bird.posY >= 1110){
            gameover = true;
        }
        
        if (!start){ //Gameplay hasn't start so the bird is just hovering up and down
            if (bird.posY > 590.f){
                bird.moveY(1);
            } else if (bird.posY <= 590.f){
                bird.moveY(-1);
            }
        } else if(gameover){ //If gameover...
            bird.moveY(-1); //Drop the dead bird down.
            text1.setString(to_string(score));
            window.draw(text1); //Display score
            window.draw(text2); //Display game over message
        } else if(!pause){ //If pause not active, then move the pipes and bird
            bird.moveY(-1);
            for (int i = 0; i < myPipes.size(); i++) {
                myPipes[i].move(-7);
            }
            //Display and updating score during game play
            text1.setString(to_string(score));
            window.draw(text1);
        }

        // Pipe loop - create new pipe when one leaves the screen
        if(myPipes[index%4].posX < -600){
            myPipes[index%4] = myPipe(myPipes[(3 + index)%4].posX + 800.f);
            index++;
        }
        
        // Adds to score when pipe passes the position of the bird
        if(myPipes[score%4].posX < 495){
            score++;
        }
        window.display();
    }
  
    return 0;
}
