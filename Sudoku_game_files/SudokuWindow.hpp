#ifndef SUDOKUWINDOW_HPP
#define SUDOKUWINDOW_HPP

#include <SFML/Graphics.hpp>

class WindowSudoku{
    public:
        WindowSudoku();

        void GameRunner();
    
        void WelcomeMessage();
        
    private:
        //Note: These two helper functions will spare the process of coding the customization of every new Text and Rectangle shape objects created.
        void AdjustTextTo(sf::Text& text, const std::string& message, unsigned int size, sf::Vector2f position, sf::Color color = sf::Color::White, std::uint32_t textStyle = sf::Text::Regular);
        void AdjustRectangleTo(sf::RectangleShape& rectangle, sf::Vector2f size, sf::Vector2f position, sf::Color fillColor = sf::Color::White, sf::Color outlineColor = sf::Color::Transparent, float outlineThickness = 0.f);

        sf::RenderWindow window;
        sf::Font style_;

        enum class Screen_Type_{
            welcome,
            config,
            game,
            pause,
        };

        void EventsManager();
        void Draw();

        void DrawWelcomeScreen();
        void DrawConfigScreen();
        void DrawGameScreen();
        void DrawPauseScreen();

        void WelcomeClickHandler(sf::Vector2f mousePosition);
        void GameClickHandler(sf::Vector2f mousePosition);

        Screen_Type_ currentScreen_;

};

#endif