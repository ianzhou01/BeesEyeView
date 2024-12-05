// /******************************
//  * File: window.h
//  * Purpose: This file declares the driver code for the whole program and runs the SFML interface to use the application.
//  * Authors: Ian Zhou
//  * Created: 12/4/2024
//  ******************************/

// #pragma once
// #include <iostream>
// #include "util.h" // Listing class and Json parsing
// #include "introsort.h"
// #include "timsort.h"
// #include <cfloat>
// #include <iomanip>
// #include <chrono> // For timing functions
// #include <SFML/Graphics.hpp>

// using namespace std;

// const int WIDTH = 1280;
// const int HEIGHT = 720;

// class Window {
// public:
//     Window();
//     void operator()();

// private:
//     sf::RenderWindow win;
//     sf::RectangleShape menuBar;
//     sf::RectangleShape resetButton;
//     sf::Font menuFont;
//     sf::Text titleText, resetText;
//     sf::Text errorText;

//     // Input fields for user parameters
//     sf::RectangleShape inputBoxLocation;
//     sf::RectangleShape inputBoxMaxPrice;
//     sf::RectangleShape inputBoxSortParameter;
//     sf::RectangleShape inputBoxSortMethod;
//     sf::RectangleShape inputBoxDisplayCount;

//     sf::Text labelLocation, labelMaxPrice, labelSortParameter, labelSortMethod, labelDisplayCount;
//     sf::Text inputTextLocation, inputTextMaxPrice, inputTextSortParameter, inputTextSortMethod, inputTextDisplayCount;

//     sf::RectangleShape outputList;
//     vector<sf::Text> listingDisplay;

//     // State variables for user input and current display
//     string locationInput;
//     int maxPriceInput;
//     int sortParameterInput;
//     int sortMethodInput;
//     int displayCountInput;

//     vector<Listing> listings; // Listings from JSON parsing

//     // Helper functions
//     void handleEvents();
//     void renderUI();
//     void resetParameters();
//     void displayListings();
//     void validateInput();
//     void fetchAndSortListings();
// };

