#include <SFML/Graphics.hpp>

int main(){
    sf::RenderWindow cliche_window(sf::VideoMode({800, 600}), "Very first window!!");
    
    while (cliche_window.isOpen()){
        while (const std::optional event = cliche_window.pollEvent()){
            if (event->is<sf::Event::Closed>()){
                cliche_window.close();
            }
        }

        cliche_window.clear();
        cliche_window.display();
    }

    return 0;
}