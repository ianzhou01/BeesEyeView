/******************************
 * File: window.h
 * Purpose: This file declares the driver code for the whole program and runs the SFML interface to use the application.
 * Authors: Ian Zhou
 * Created: 12/4/2024
 ******************************/

#pragma once
#include <iostream>
#include <unordered_map>
#include <cfloat>
#include <iomanip>
#include <chrono> // For timing functions
#include "button.h"
#include "introsort.h"
#include "timsort.h"
#include "util.h" // Listing class and Json parsing

using namespace std;

const int WIDTH = 1280;
const int HEIGHT = 720;

enum InputBoxType { None, Latitude, Longitude, MaxPrice, DisplayCount };

class Window {
public:
    Window();
    void operator()();

private:
    InputBoxType activeInputBox = None; // Tracks which input box is active
    unordered_map<InputBoxType, string> inputStrings; // Store all input strings
    unordered_map<InputBoxType, sf::Text> inputTexts;


    sf::RenderWindow win;
    sf::RectangleShape menuBar;
    Button resetButton, runButton;
    sf::Font menuFont;
    sf::Text titleText;
    sf::Text errorText, sortText;

    sf::RectangleShape scrollBar; // Visual scroll bar
    sf::Vector2f scrollOffset;   // Offset for scrolling
    float scrollSpeed = 20.0f;

    sf::Text cursor; // Blinking cursor
    bool cursorVisible = true; // Cursor visibility
    sf::Clock cursorClock; // Clock to manage blinking

    // Input fields for user parameters
    sf::RectangleShape inputBoxLat, inputBoxLong;
    sf::RectangleShape inputBoxMaxPrice;
    sf::RectangleShape methodDropdownButton, paramDropdownButton;
    sf::RectangleShape inputBoxDisplayCount;
    sf::Text methodDropdownButtonText, paramDropdownButtonText;

    vector<sf::RectangleShape> sortMethodOptions, sortParamOptions;
    vector<sf::Text> sortMethodOptionTexts, sortParamOptionTexts;
    bool isMethodDropdownOpen = false, isParamDropdownOpen = false;
    int methodOption = -1, paramOption = -1;

    sf::Text latLocation, longLocation, labelMaxPrice, labelSortMethod, labelSortParam, labelDisplayCount;

    sf::RectangleShape outputList;
    vector<sf::Text> listingDisplay;

    // State variables for user input and current display
    float lat, lon;
    int maxPrice, dispCt;
    bool displayed;

    vector<Listing> listings; // Listings from JSON parsing

    // Helper functions
    void renderUI();
    void resetParameters();
    void displayListings(const vector<Listing>&, int n);
    void handleScroll(const sf::Event& event, size_t totalListings);
};

sf::Text renderText(const std::string& msg, const sf::Font& font, int size, sf::Color color, bool bold, bool underlined);