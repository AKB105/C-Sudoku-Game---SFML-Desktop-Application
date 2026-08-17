#include <SFML/Graphics.hpp> //Graphic library

int main(){
    sf::RenderWindow cliche_window(sf::VideoMode({800, 600}), "Very first window!!"); //Creates a 800*600 window titled "Very first window!!"
    
    //Constantly checks if the window is still open with isOpen() function
    while (cliche_window.isOpen()){
        //... Got no idea wtf is this thing doing, gotta study it more...
        while (const std::optional event = cliche_window.pollEvent()){
            //Some weird conditioned if-statement that checks for an event that, closes the window? I guess...
            if (event->is<sf::Event::Closed>()){
                cliche_window.close();
            }
        }

        //If the condition from above was not met, then the window will just clear itself and display the content within
        //which is nothing... Yet.
        cliche_window.clear();
        cliche_window.display();
    }

    return 0;
}