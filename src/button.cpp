/******************************
 * File: button.h
 * Purpose: This file defines the Button class for SFML interface
 * Authors: Ian Zhou
 * Created: 12/4/2024
 ******************************/

#include "button.h"

Button::Button() : originalColor(sf::Color::Blue), darkColor(sf::Color::Green), clicked(false) {
    shape.setSize(sf::Vector2f(100.f, 50.f)); // Default size
    shape.setPosition(0.f, 0.f);             // Default position
    shape.setFillColor(originalColor);       // Default color
    text.setCharacterSize(20);              // Default text size
}

Button::Button(float x, float y, float width, float height, const string &buttonText, const sf::Font &font,
               sf::Color fillColor, sf::Color textColor) :
               originalColor(fillColor),
               darkColor(fillColor.r / 2,fillColor.g / 2,fillColor.b / 2),
               clicked(false)
{
    shape.setSize(sf::Vector2f(width, height));
    shape.setPosition(x, y);
    shape.setFillColor(fillColor);

    text.setFont(font);
    text.setString(buttonText);
    text.setFillColor(textColor);
    text.setCharacterSize(20); // Default character size

    centerText();              // Automatically center text within the button
}

void Button::draw(sf::RenderWindow &window) const {
    window.draw(shape); // Draw the button
    window.draw(text);
}

bool Button::isMouseOver(const sf::Vector2f &mousePos) const {
    return shape.getGlobalBounds().contains(mousePos); // Check if mouse is over the button
}

sf::Vector2f Button::getPosition() {
    return shape.getPosition();
}

// Button state functions
void Button::update(const sf::Vector2f& mousePos) {
    // Check if the mouse is over the button and left-clicked
    clicked = isMouseOver(mousePos) && sf::Mouse::isButtonPressed(sf::Mouse::Left);

    if (clicked) {
        shape.setFillColor(darkColor); // Darker color when clicked
    }
    else {
        shape.setFillColor(originalColor); // Reset to original color
    }
}

void Button::centerText() {
    sf::FloatRect textBounds = text.getLocalBounds();
    sf::FloatRect buttonBounds = shape.getGlobalBounds();
    text.setPosition(
            buttonBounds.left + (buttonBounds.width - textBounds.width) / 2.0f - textBounds.left,
            buttonBounds.top + (buttonBounds.height - textBounds.height) / 2.0f - textBounds.top
    );
}

