/******************************
 * File: button.h
 * Purpose: This file declares a Button class for SFML interface
 * Authors: Ian Zhou
 * Created: 12/4/2024
 ******************************/

#pragma once
#include <SFML/Graphics.hpp>
using namespace std;

struct Button {
    sf::RectangleShape shape;   // Rectangle for the button
    sf::Color originalColor;    // Original button color
    sf::Color darkColor;        // Darker color when clicked
    sf::Text text;
    bool clicked;               // Button clicked state

    Button();
    explicit Button(float x, float y, float width, float height, const std::string& buttonText, const sf::Font& font,
                    sf::Color fillColor = sf::Color::Blue, sf::Color textColor = sf::Color::White);
    void draw(sf::RenderWindow &window) const;

    // Button state functions
    void update(const sf::Vector2f &mousePos);
    bool isMouseOver(const sf::Vector2f &mousePos) const;
    sf::Vector2f getPosition();
private:
    void centerText();
};
