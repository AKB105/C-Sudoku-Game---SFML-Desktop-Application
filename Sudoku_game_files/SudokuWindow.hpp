#ifndef SUDOKUWINDOW_HPP
#define SUDOKUWINDOW_HPP

#include <SFML/Graphics.hpp>

class WindowSudoku{
    public:
        WindowSudoku();
        void WelcomeMessage();

    private:
        sf::RenderWindow window;
        sf::Font style_;

        enum class Screen_Type_{
            welcome,
            config,
            game,
            pause,
        };
    
};

#endif