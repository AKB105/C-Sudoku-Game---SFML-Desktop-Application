#include "SudokuWindow.hpp"
#include <iostream>

//Constructor of the class. So far it only checks if the fonts loaded properly.
WindowSudoku::WindowSudoku():window(sf::VideoMode({800,600}), "Sudoku"){
    currentScreen_= Screen_Type_::welcome;

    if(!style_.openFromFile("../Assets/Fonts/Silkscreen-Regular.ttf")){
        std::cout << "Font didn't load." << std::endl;
    }
}

void WindowSudoku::AdjustTextTo(sf::Text& text, const std::string& message, unsigned int size, sf::Vector2f position, sf::Color color, std::uint32_t textStyle){
    text.setString(message);
    text.setCharacterSize(size);
    text.setPosition(position);
    text.setFillColor(color);
    text.setStyle(textStyle);
}

void WindowSudoku::AdjustRectangleTo(sf::RectangleShape& rectangle, sf::Vector2f size, sf::Vector2f position, sf::Color fillColor, sf::Color outlineColor, float outlineThickness){
    rectangle.setSize(size);
    rectangle.setPosition(position);
    rectangle.setFillColor(fillColor);
    rectangle.setOutlineColor(outlineColor);
    rectangle.setOutlineThickness(outlineThickness);
}

void WindowSudoku::EventsManager(){
    while(const std::optional action = window.pollEvent()){
        if(action->is<sf::Event::Closed>()){
            window.close();
        }
        if (const auto* mousePressed = action->getIf<sf::Event::MouseButtonPressed>()) {
            if (mousePressed->button == sf::Mouse::Button::Left) {
                sf::Vector2f mousePosition(static_cast<float>(mousePressed->position.x), static_cast<float>(mousePressed->position.y));
            }
        }
    }
}

void WindowSudoku::Draw(){
    
}

void WindowSudoku::DrawWelcomeScreen(){
    sf::Text title(style_);
    AdjustTextTo(title, "||Welcome to Sudoku!!||\n", 48, {60.f, 20.f}, sf::Color::White, sf::Text::Underlined);

    sf::Text rules(style_);
    AdjustTextTo(rules, "First time playing? Click here for instructions.\n\n", 24, {5.f, 100.f}, sf::Color::White, sf::Text::Bold);

    sf::Text play_button(style_);
    AdjustTextTo(play_button, "Play", 48, {330.f, 400.f});

    sf::RectangleShape little_box({100.f, 100.f});
    AdjustRectangleTo(little_box, {200.f, 80.f}, {300.f, 400.f}, sf::Color::Transparent, sf::Color::White, 5.f);

    window.draw(title);
    window.draw(rules);
    window.draw(play_button);
    window.draw(little_box);
}

void WindowSudoku::DrawConfigScreen(){

}

void WindowSudoku::DrawGameScreen(){

}

void WindowSudoku::DrawPauseScreen(){

}

void WindowSudoku::WelcomeClickHandler(sf::Vector2f mousePosition){
    
}

void WindowSudoku::GameClickHandler(sf::Vector2f mousePosition){
    
}

void WindowSudoku::GameRunner(){
    while(window.isOpen()){
        EventsManager();

        window.clear();

        switch (currentScreen_){
            case Screen_Type_::welcome:
                DrawWelcomeScreen();
                break;
            case Screen_Type_::config:
                DrawConfigScreen();
                break;
            case Screen_Type_::game:
                DrawGameScreen();
                break;
            case Screen_Type_::pause:
                DrawPauseScreen();
                break;
            default:
                std::cout << "WARNING: Something went wrong!" << std::endl;
                break;
        }

        window.display();
    }
}