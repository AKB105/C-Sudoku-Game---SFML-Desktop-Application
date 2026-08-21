//!README: Copy the line below, paste it down in the terminal to create the .exe.
//g++ -std=c++17 sf_test3_shapes.cpp -o sfml_test_3 -lsfml-graphics -lsfml-window -lsfml-system
//!README: Copy this to execute the .exe created.
//.\sfml_test_3.exe
//!------------------------------------------------------------------------------------

#include "SFML/Graphics.hpp"
#include <iostream>

int main(){
    bool buttonPressed = false;

    sf::RenderWindow window_Block(sf::VideoMode({800, 600}), "Message in blocks!!"); //Creates a 800*600 window titled "Message in blocks!!"
    sf::Font style;
    
    //The if-statement guarantees that style variable gets a file to hold and load
    //(with the .openFromFile() function), and a measure in case it fails.
    if(!style.openFromFile("../Assets/Fonts/Silkscreen-Regular.ttf")) { //Update: You can use relative file paths for organization purposes, instead of just writing the file name
        //Message indicating that font couldn't be loaded.
        std::cout << "Font cannot be loaded" << std::endl; //Most familiar shit I'll see during this try-outs, cout!!
        return 1; //This is not a simple program anymore, a font not loading is a huge thing, the code must end before doing some crazy stuff.
    } 

    //Note: Main message that will be displayed---------------------------------------
    sf::Text message(style); //Note: Every text object requires a FONT as argument

    message.setString("Hello, World!!"); //Note: Write what you wanna display
    message.setCharacterSize(64); //Note: The size is measured by pixels, not points (To self: Points are a typography measurement used in stuff like Word. 72 points = 1 inch to print.)
    message.setFillColor(sf::Color::White); //Note: Sets the color, I-I think this is self-explainatory
    message.setStyle(sf::Text::Italic); //Note: You can also pass combinations like sf::Text::Bold | sf::Text::Underlined
    message.setPosition({115.f,225.f}); //Note: The (0,0) coordinate for this is at the top left corner of the window, thus, x goes right and y goes down. (P.D: f stands for float)
    
    //Note: Block for the main message---------------------------------------
    sf::RectangleShape borders({575.f, 75.f});

    borders.setFillColor(sf::Color::Transparent);
    borders.setOutlineThickness(5.f);
    borders.setOutlineColor(sf::Color::White);
    borders.setPosition({115.f,230.f});

    //Note: "Next" button to display new message---------------------------------------
    sf::Text next(style);

    next.setString("Next message");
    next.setCharacterSize(32);
    next.setFillColor(sf::Color::Black);
    next.setStyle(sf::Text::Bold);
    next.setPosition({250.f, 400.f});

    //Note: Block for the "next" button---------------------------------------
    sf::RectangleShape little_box({315.f, 100.f});

    little_box.setFillColor(sf::Color::Transparent);
    little_box.setOutlineThickness(5.f);
    little_box.setOutlineColor(sf::Color::White);
    little_box.setPosition({240.f,375.f});
    
    //Constantly checks if the window is still open with isOpen() function, constantly renovating the screen frame by frame... Is a render loop.
    while (window_Block.isOpen()){
        //The while keeps running as long as there are events happening
        //Update: The optional object "event" contains A POSSIBLE action that was done and returned by pollEvent().
        //Reminder: Const is a safety measure so that the object cannot be modified no matter what
        while (const std::optional event = window_Block.pollEvent()){
            //If the event (user's action) that ocurred is closing the window (i.e. pressing x bottom on the corner, or clicking an exit game button), then the window gets closed.
            if (event->is<sf::Event::Closed>()){
                window_Block.close();
            }
            //Pretty much checks if one of the mouse buttons were pressed, specifically the left one, checks the coordinates where it clicked, 
            //then checks if those coordinates are inside the area of little_box
            if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()){
                if(mousePressed->button == sf::Mouse::Button::Left){
                    sf::Vector2f mousePosition(static_cast<float>(mousePressed->position.x), static_cast<float>(mousePressed->position.y));
                    if(little_box.getGlobalBounds().contains(mousePosition)){
                        buttonPressed = true;
                    }
                }
            }
        }

        //Updates the screen with every change that happened due to user action
        if(buttonPressed == true){
            window_Block.clear(sf::Color::Magenta);

            sf::RectangleShape grid({60.f, 60.f});
            
            grid.setFillColor(sf::Color::Transparent);
            grid.setOutlineThickness(5.f);
            grid.setOutlineColor(sf::Color::White);
            grid.setPosition({0.f,0.f});

            //Notes: This is the basis for my sudoku grid... A little step for man, a big one for SUDOKU!!
            for (float i = 0; i < 9; i++){
                for(float j = 0; j < 9; j++){
                    grid.setPosition({100.f + j * 60.f, 30.f + i * 60.f});
                    window_Block.draw(grid);
                }
            }

        } else{
            window_Block.clear(sf::Color::Red); //Calling clear before drawing anything is mandatory, 
                                                //otherwise the contents from previous frames will be present behind anything you draw.
            window_Block.draw(message);
            window_Block.draw(borders);
    
            window_Block.draw(next);
            window_Block.draw(little_box);
        };                                     

        window_Block.display(); //Calling display is also mandatory, it takes what was drawn since the last call to display and displays it on the window. 
                                //Indeed, things are not drawn directly to the window, but to a hidden buffer. 
                                //This buffer is then copied to the window when you call display -- this is called double-buffering.
    }

    return 0;
}