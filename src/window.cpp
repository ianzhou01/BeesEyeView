// /******************************
//  * File: window.cpp
//  * Purpose: This file contains the driver code for the whole program and runs the SFML interface to use the application.
//  * Authors: Ian Zhou
//  * Created: 12/4/2024
//  ******************************/

// #include "window.h"

// Window::Window() : win(sf::VideoMode(WIDTH, HEIGHT), "Bee's Eye View") {
//     if (!menuFont.loadFromFile("include/FiraSans-Regular.ttf"))
//         throw runtime_error("Error loading font from FiraSans-Regular.ttf!\n");

//     // Title Text
//     titleText.setFont(menuFont);
//     titleText.setString("Bee's Eye View");
//     titleText.setCharacterSize(32);
//     titleText.setFillColor(sf::Color::White);
//     titleText.setPosition(WIDTH / 2.0f - titleText.getGlobalBounds().width / 2.0f, 10);

//     // Reset Button
//     resetButton.setSize(sf::Vector2f(100, 40));
//     resetButton.setFillColor(sf::Color(100, 100, 200));
//     resetButton.setPosition(WIDTH - 120, 10);

//     resetText.setFont(menuFont);
//     resetText.setString("Reset");
//     resetText.setCharacterSize(20);
//     resetText.setFillColor(sf::Color::White);
//     resetText.setPosition(resetButton.getPosition().x + 25, resetButton.getPosition().y + 5);

//     // Error Text (initially hidden)
//     errorText.setFont(menuFont);
//     errorText.setString("");
//     errorText.setCharacterSize(18);
//     errorText.setFillColor(sf::Color::Red);
//     errorText.setPosition(WIDTH / 2.0f - 150, HEIGHT - 50);

//     // Input Labels
//     labelLocation.setFont(menuFont);
//     labelLocation.setString("Enter Location (lat lon):");
//     labelLocation.setCharacterSize(20);
//     labelLocation.setFillColor(sf::Color::White);
//     labelLocation.setPosition(50, 100);

//     labelMaxPrice.setFont(menuFont);
//     labelMaxPrice.setString("Maximum Room Rate ($):");
//     labelMaxPrice.setCharacterSize(20);
//     labelMaxPrice.setFillColor(sf::Color::White);
//     labelMaxPrice.setPosition(50, 200);

//     labelSortParameter.setFont(menuFont);
//     labelSortParameter.setString("Sort By (1: Distance, 2: Price):");
//     labelSortParameter.setCharacterSize(20);
//     labelSortParameter.setFillColor(sf::Color::White);
//     labelSortParameter.setPosition(50, 300);

//     labelSortMethod.setFont(menuFont);
//     labelSortMethod.setString("Sort Method (1: Timsort, 2: Introsort):");
//     labelSortMethod.setCharacterSize(20);
//     labelSortMethod.setFillColor(sf::Color::White);
//     labelSortMethod.setPosition(50, 400);

//     labelDisplayCount.setFont(menuFont);
//     labelDisplayCount.setString("Number of Entries to Display:");
//     labelDisplayCount.setCharacterSize(20);
//     labelDisplayCount.setFillColor(sf::Color::White);
//     labelDisplayCount.setPosition(50, 500);

//     // Input Boxes
//     inputBoxLocation.setSize(sf::Vector2f(300, 40));
//     inputBoxLocation.setFillColor(sf::Color(200, 200, 200));
//     inputBoxLocation.setPosition(350, 100);

//     inputBoxMaxPrice.setSize(sf::Vector2f(300, 40));
//     inputBoxMaxPrice.setFillColor(sf::Color(200, 200, 200));
//     inputBoxMaxPrice.setPosition(350, 200);

//     inputBoxSortParameter.setSize(sf::Vector2f(300, 40));
//     inputBoxSortParameter.setFillColor(sf::Color(200, 200, 200));
//     inputBoxSortParameter.setPosition(350, 300);

//     inputBoxSortMethod.setSize(sf::Vector2f(300, 40));
//     inputBoxSortMethod.setFillColor(sf::Color(200, 200, 200));
//     inputBoxSortMethod.setPosition(350, 400);

//     inputBoxDisplayCount.setSize(sf::Vector2f(300, 40));
//     inputBoxDisplayCount.setFillColor(sf::Color(200, 200, 200));
//     inputBoxDisplayCount.setPosition(350, 500);

//     // Initialize State Variables
//     locationInput = "";
//     maxPriceInput = 0;
//     sortParameterInput = 0;
//     sortMethodInput = 0;
//     displayCountInput = 0;

//     // Listings Display
//     outputList.setSize(sf::Vector2f(500, 500));
//     outputList.setFillColor(sf::Color(50, 50, 50));
//     outputList.setPosition(700, 100);
// }


// void Window::operator()() {

// }

// void Window::handleEvents() {

// }

// void Window::renderUI() {

// }

// void Window::resetParameters() {

// }

// void Window::displayListings() {

// }

// void Window::validateInput() {

// }

// void Window::fetchAndSortListings() {

// }

