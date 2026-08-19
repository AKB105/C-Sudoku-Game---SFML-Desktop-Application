#include "SudokuWindow.hpp"
#include <iostream>

WindowSudoku::WindowSudoku():window(sf::VideoMode({800,600}), "Sudoku"){
    if(!style_.openFromFile("../Assets/Fonts/Silkscreen-Regular.ttf")){
        std::cout << "Font didn't load." << std::endl;
    }
}

void WindowSudoku::WelcomeMessage(){
    sf::Text title(style_);
    title.setString("||Welcome to Sudoku!!||\n"
                    "=======================\n\n");
    title.setCharacterSize(48);
    title.setPosition({60.f, 20.f});

    sf::Text rules(style_);
    rules.setString("Complete the game by filling in the missing numbers.\n\n");
    rules.setCharacterSize(23);
    rules.setPosition({5.f,120.f});

    while(window.isOpen()){
        while(const std::optional action = window.pollEvent()){
            if(action->is<sf::Event::Closed>()){
                window.close();
            }
        }

        window.clear();
        window.draw(title);
        window.draw(rules);
        window.display();
    }
}

