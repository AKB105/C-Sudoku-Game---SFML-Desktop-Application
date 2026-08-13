//!README: Copy the line below, paste it down in the terminal to create the .exe.
//g++ -std=c++17 sfml_test_2_helloworld.cpp -o sfml_test_2 -lsfml-graphics -lsfml-window -lsfml-system
//!README: Copy this to execute the .exe created.
//.\sfml_test_2.exe
//!------------------------------------------------------------------------------------
#include <SFML/Graphics.hpp> //Graphic library
#include <iostream>

int main(){
    sf::RenderWindow hiWindow(sf::VideoMode({800, 600}), "Salutation window!!"); //Creates a 800*600 window titled "Very first window!!"
    sf::Font style;
    
    //The if-statement guarantees that style variable gets a file to hold and load
    //(with the .openFromFile() function), and a measure in case it fails.
    if(!style.openFromFile("../Assets/Fonts/Silkscreen-Regular.ttf")) { //Update: You can use relative file paths for organization purposes, instead of just writing the file name
        //Message indicating that font couldn't be loaded.
        std::cout << "Font cannot be loaded" << std::endl; //Most familiar shit I'll see during this try-outs, cout!!
        return 1; //This is not a simple program anymore, a font not loading is a huge thing, the code must end before doing some crazy stuff.
    } 

    sf::Text message(style); //Note: Every text object requires a FONT as argument
    message.setString("Hello, World!!"); //Note: Write what you wanna display
    message.setCharacterSize(64); //Note: The size is measured by pixels, not points (To self: Points are a typography measurement used in stuff like Word. 72 points = 1 inch to print.)
    message.setFillColor(sf::Color::White); //Note: Sets the color, I-I think this is self-explainatory
    message.setStyle(sf::Text::Italic); //Note: You can also pass combinations like sf::Text::Bold | sf::Text::Underlined
    message.setPosition({115.f,225.f}); //Note: The (0,0) coordinate for this is at the top left corner of the window, thus, x goes right and y goes down. (P.D: f stands for float)
    
    //Constantly checks if the window is still open with isOpen() function, constantly renovating the screen frame by frame... Is a render loop.
    while (hiWindow.isOpen()){
        //The while keeps running as long as there are events happening
        //Update: The optional object "event" contains A POSSIBLE action that was done and returned by pollEvent().
        //Reminder: Const is a safety measure so that the object cannot be modified no matter what
        while (const std::optional event = hiWindow.pollEvent()){
            //If the event (user's action) that ocurred is closing the window (i.e. pressing x bottom on the corner, or clicking an exit game button), then the window gets closed.
            if (event->is<sf::Event::Closed>()){
                hiWindow.close();
            }
        }

        //Updates the screen with every change that happened due to user action
        //which is nothing... Yet.
        hiWindow.clear();
        hiWindow.draw(message);
        hiWindow.display();
    }

    return 0;
}