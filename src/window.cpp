/******************************
 * File: window.cpp
 * Purpose: This file contains the driver code for the whole program and runs the SFML interface to use the application.
 * Authors: Ian Zhou
 * Created: 12/4/2024
 ******************************/

#include "window.h"

Window::Window() : win(sf::VideoMode(WIDTH, HEIGHT), "Bee's Eye View") {
    if (!menuFont.loadFromFile("../include/FiraSans-Regular.ttf"))
        throw runtime_error("Error loading font from FiraSans-Regular.ttf!\n");

    // Load JSON filenames
    for (int i=1; i<=40; ++i) {
        loadFiles.push_back("../data/all_data/split_" + to_string(i) + ".json");
    }

    // Title Text
    titleText.setFont(menuFont);
    titleText.setString("Bee's Eye View");
    titleText.setCharacterSize(32);
    titleText.setFillColor(sf::Color::Yellow);
    titleText.setPosition(WIDTH / 2.0f - titleText.getGlobalBounds().width / 2.0f, 10);

    resetButton = Button(WIDTH - 120, 10, 100, 40, "Reset", menuFont);
    runButton = Button(WIDTH - 240, 10, 100, 40, "Run", menuFont);

    // Error Text (initially hidden)
    errorText.setFont(menuFont);
    errorText.setString("");
    errorText.setCharacterSize(18);
    errorText.setFillColor(sf::Color::Red);
    errorText.setPosition(WIDTH / 2.0f - 150, HEIGHT - 50);

    sortText.setFont(menuFont);
    sortText.setString("");
    sortText.setCharacterSize(18);
    sortText.setFillColor(sf::Color::White);
    sortText.setPosition(WIDTH / 2.0f - 150, HEIGHT - 50);

    // Input Labels
    latLocation.setFont(menuFont);
    latLocation.setString("Latitude (degrees):");
    latLocation.setCharacterSize(20);
    latLocation.setFillColor(sf::Color::White);
    latLocation.setPosition(50, 100);

    longLocation.setFont(menuFont);
    longLocation.setString("Longitude (degrees):");
    longLocation.setCharacterSize(20);
    longLocation.setFillColor(sf::Color::White);
    longLocation.setPosition(50, 150);

    labelMaxPrice.setFont(menuFont);
    labelMaxPrice.setString("Maximum Room Rate ($):");
    labelMaxPrice.setCharacterSize(20);
    labelMaxPrice.setFillColor(sf::Color::White);
    labelMaxPrice.setPosition(50, 225);

    labelSortMethod.setFont(menuFont);
    labelSortMethod.setString("Sorting Algorithm: ");
    labelSortMethod.setCharacterSize(20);
    labelSortMethod.setFillColor(sf::Color::White);
    labelSortMethod.setPosition(50, 300);

    labelSortParam.setFont(menuFont);
    labelSortParam.setString("Return Results By: ");
    labelSortParam.setCharacterSize(20);
    labelSortParam.setFillColor(sf::Color::White);
    labelSortParam.setPosition(50, 450);

    cursor = renderText("|", menuFont, 18, sf::Color::Black, false, false);

    // Dropdown Button
    methodDropdownButton.setSize(sf::Vector2f(300, 40));
    methodDropdownButton.setFillColor(sf::Color(200, 200, 200));
    methodDropdownButton.setPosition(350, 300);

    methodDropdownButtonText.setFont(menuFont);
    methodDropdownButtonText.setString("Sort By");
    methodDropdownButtonText.setCharacterSize(20);
    methodDropdownButtonText.setFillColor(sf::Color::Black);
    methodDropdownButtonText.setPosition(methodDropdownButton.getPosition().x + 10, methodDropdownButton.getPosition().y + 5);

    paramDropdownButton.setSize(sf::Vector2f(300, 40));
    paramDropdownButton.setFillColor(sf::Color(200, 200, 200));
    paramDropdownButton.setPosition(350, 450);

    paramDropdownButtonText.setFont(menuFont);
    paramDropdownButtonText.setString("Sort By");
    paramDropdownButtonText.setCharacterSize(20);
    paramDropdownButtonText.setFillColor(sf::Color::Black);
    paramDropdownButtonText.setPosition(paramDropdownButton.getPosition().x + 10, paramDropdownButton.getPosition().y + 5);

    scrollBar.setSize(sf::Vector2f(20, 100)); // Width and initial height of the scrollbar
    scrollBar.setFillColor(sf::Color::White);
    scrollBar.setPosition(outputList.getPosition().x + outputList.getSize().x - 20, outputList.getPosition().y);
    scrollOffset = sf::Vector2f(0, 0);

    // Dropdown Options
    vector<string> methodOptions = {"Introsort", "Timsort"};
    for (int i = 0; i < methodOptions.size(); ++i) {
        sf::RectangleShape option(sf::Vector2f(300, 40));
        option.setFillColor(sf::Color(200, 200, 200));
        option.setPosition(methodDropdownButton.getPosition().x, methodDropdownButton.getPosition().y + ((i+1) * (option.getSize().y + 5))); // Position the paramOptions below the dropdown button
        sortMethodOptions.push_back(option);

        sf::Text optionText;
        optionText.setFont(menuFont);
        optionText.setString(methodOptions[i]);
        optionText.setCharacterSize(20);
        optionText.setFillColor(sf::Color::Black);
        optionText.setPosition(option.getPosition().x + 10, option.getPosition().y + 5);
        sortMethodOptionTexts.push_back(optionText);
    }

    vector<string> paramOptions = {"Distance", "Price"};
    for (int i = 0; i < paramOptions.size(); ++i) {
        sf::RectangleShape option(sf::Vector2f(300, 40));
        option.setFillColor(sf::Color(200, 200, 200));
        option.setPosition(paramDropdownButton.getPosition().x, paramDropdownButton.getPosition().y + ((i+1) * (option.getSize().y + 5))); // Position the paramOptions below the dropdown button
        sortParamOptions.push_back(option);

        sf::Text optionText;
        optionText.setFont(menuFont);
        optionText.setString(paramOptions[i]);
        optionText.setCharacterSize(20);
        optionText.setFillColor(sf::Color::Black);
        optionText.setPosition(option.getPosition().x + 10, option.getPosition().y + 5);
        sortParamOptionTexts.push_back(optionText);
    }

    labelDisplayCount.setFont(menuFont);
    labelDisplayCount.setString("Number of Entries to Display:");
    labelDisplayCount.setCharacterSize(20);
    labelDisplayCount.setFillColor(sf::Color::White);
    labelDisplayCount.setPosition(50, 600);

    // Input Boxes
    inputBoxLat.setSize(sf::Vector2f(300, 40));
    inputBoxLat.setFillColor(sf::Color(200, 200, 200));
    inputBoxLat.setPosition(350, 100);
    inputBoxHeights[Latitude] = 100;


    inputBoxLong.setSize(sf::Vector2f(300, 40));
    inputBoxLong.setFillColor(sf::Color(200, 200, 200));
    inputBoxLong.setPosition(350, 150);
    inputBoxHeights[Longitude] = 150;


    inputBoxMaxPrice.setSize(sf::Vector2f(300, 40));
    inputBoxMaxPrice.setFillColor(sf::Color(200, 200, 200));
    inputBoxMaxPrice.setPosition(350, 225);
    inputBoxHeights[MaxPrice] = 225;


    inputBoxDisplayCount.setSize(sf::Vector2f(300, 40));
    inputBoxDisplayCount.setFillColor(sf::Color(200, 200, 200));
    inputBoxDisplayCount.setPosition(350, 600);
    inputBoxHeights[DisplayCount] = 600;

    // Listings Display
    outputList.setSize(sf::Vector2f(500, 500));
    outputList.setFillColor(sf::Color(50, 50, 50));
    outputList.setPosition(700, 100);

    inputStrings[Latitude] = "";
    inputStrings[Longitude] = "";
    inputStrings[MaxPrice] = "";
    inputStrings[DisplayCount] = "";

    sf::Text latitudeText = renderText("", menuFont, 20, sf::Color::Black, false, false);
    latitudeText.setPosition(inputBoxLat.getPosition().x + 10, inputBoxLat.getPosition().y + 5);
    inputTexts[Latitude] = latitudeText;

    sf::Text longitudeText = renderText("", menuFont, 20, sf::Color::Black, false, false);
    longitudeText.setPosition(inputBoxLong.getPosition().x + 10, inputBoxLong.getPosition().y + 5);
    inputTexts[Longitude] = longitudeText;

    sf::Text maxPriceText = renderText("", menuFont, 20, sf::Color::Black, false, false);
    maxPriceText.setPosition(inputBoxMaxPrice.getPosition().x + 10, inputBoxMaxPrice.getPosition().y + 5);
    inputTexts[MaxPrice] = maxPriceText;

    sf::Text displayCountText = renderText("", menuFont, 20, sf::Color::Black, false, false);
    displayCountText.setPosition(inputBoxDisplayCount.getPosition().x + 10, inputBoxDisplayCount.getPosition().y + 5);
    inputTexts[DisplayCount] = displayCountText;

    resetParameters();
}

void Window::operator()() {
    try {
        while (win.isOpen()) {
            sf::Event event;
            sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(win)); // Get mouse position

            while (win.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    win.close();
                }
                resetButton.update(mousePos); // Update button color if pressed
                runButton.update(mousePos);

                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Tab) {
                    activeInputBox = getNextInputBox(activeInputBox);
                    cursorVisible = true;
                    cursorClock.restart();
                }

                // Mouse click handling
                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                    if (resetButton.clicked) {
                        resetParameters(); // Reset application state
                    } else {
                        errorText.setString(""); // Reset error anyway
                    }
                    if (runButton.clicked) {
                        // Run JSON parsing and sorting
                        displayed = false; // No display results yet

                        // Check if filled
                        bool allFilled = true;
                        for (const auto& [x, y] : inputStrings) {
                            if (y.empty() || y == "-") {
                                allFilled = false;
                            }
                        }
                        if (methodOption == -1 || paramOption == -1)
                            allFilled = false;

                        if (allFilled) {
                            lat = stof(inputStrings[Latitude]);
                            lon = stof(inputStrings[Longitude]);
                            maxPrice = stoi(inputStrings[MaxPrice]);
                            dispCt = stoi(inputStrings[DisplayCount]);

                            if (lat < -90 || lat > 90 || lon < -180 || lon > 180 || dispCt > 15) {
                                if (lat < -90 || lat > 90) {
                                    errorText.setString("Enter latitude between -90 to 90 degrees!");
                                } else if (lon < -180 || lon > 180) {
                                    errorText.setString("Enter longitude between -180 to 180 degrees!");
                                } else if (dispCt > 15) {
                                    errorText.setString("Can display maximum of 15 entries");
                                }
                            } else { // Run stuff
                                vector<Listing> container;
                                if (!getAllListings(container, maxPrice,
                                                 loadFiles,
                                                 {lat, lon})) {
                                    throw runtime_error("Failed to load listings from JSON!\n");
                                }
                                auto distComp = [](const Listing& a, const Listing& b)-> bool {
                                    return a.distance < b.distance;
                                };
                                if (methodOption == 0) {
                                    // Introsort
                                    auto start = chrono::high_resolution_clock::now();
                                    intro::sort(container, listComp(distComp));
                                    if (paramOption == 1) {
                                        // Sort top numListings by price
                                        auto priceComp = [](const Listing &a, const Listing &b) -> bool {
                                            return a.price < b.price;
                                        };
                                        intro::sort(container, 0, min(dispCt, (int)container.size()), listComp(priceComp));
                                    }
                                    auto end = chrono::high_resolution_clock::now();
                                    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
                                    sortText.setString("Sorted through " + to_string(container.size()) +
                                                        " available listings in " + to_string(duration.count()) + " ms.");
                                    displayed = true;
                                } else if (methodOption == 1) {
                                    auto start = chrono::high_resolution_clock::now();
                                    tim::sort(container, listComp(distComp));
                                    if (paramOption == 1) {
                                        // Sort top numListings by price
                                        auto priceComp = [](const Listing &a, const Listing &b) -> bool {
                                            return a.price < b.price;
                                        };
                                        tim::sort(container, 0, min(dispCt, (int)container.size()), listComp(priceComp));
                                    }
                                    auto end = chrono::high_resolution_clock::now();
                                    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
                                    sortText.setString("Sorted through " + to_string(container.size()) +
                                                       " available listings in " + to_string(duration.count()) +
                                                       " ms.");
                                    displayed = true;
                                }
                            }
                        } else {
                            errorText.setString("Please enter all fields!");
                        }
                    }
                    if (methodDropdownButton.getGlobalBounds().contains(mousePos)) {
                        isMethodDropdownOpen = !isMethodDropdownOpen;
                        isParamDropdownOpen = false;
                    }
                    if (paramDropdownButton.getGlobalBounds().contains(mousePos)) {
                        isParamDropdownOpen = !isParamDropdownOpen; // Toggle dropdown
                        isMethodDropdownOpen = false;
                    }
                    // Check dropdown options
                    if (isMethodDropdownOpen) {
                        for (int i = 0; i < sortMethodOptions.size(); ++i) {
                            if (sortMethodOptions[i].getGlobalBounds().contains(mousePos)) {
                                methodOption = i;
                                methodDropdownButtonText.setString(sortMethodOptionTexts[methodOption].getString());
                                isMethodDropdownOpen = false; // Close dropdown
                                break;
                            }
                        }
                    }
                    if (isParamDropdownOpen) {
                        for (int i = 0; i < sortParamOptions.size(); ++i) {
                            if (sortParamOptions[i].getGlobalBounds().contains(mousePos)) {
                                paramOption = i;
                                paramDropdownButtonText.setString(sortParamOptionTexts[paramOption].getString());
                                isParamDropdownOpen = false; // Close dropdown
                                break;
                            }
                        }
                    }
                    // Run other input boxes
                    if (inputBoxLat.getGlobalBounds().contains(mousePos)) {
                        activeInputBox = Latitude;
                        cursorVisible = true;
                        cursorClock.restart();
                    } else if (inputBoxLong.getGlobalBounds().contains(mousePos)) {
                        activeInputBox = Longitude;
                        cursorVisible = true;
                        cursorClock.restart();
                    } else if (inputBoxMaxPrice.getGlobalBounds().contains(mousePos)) {
                        activeInputBox = MaxPrice;
                        cursorVisible = true;
                        cursorClock.restart();
                    } else if (inputBoxDisplayCount.getGlobalBounds().contains(mousePos)) {
                        activeInputBox = DisplayCount;
                        cursorVisible = true;
                        cursorClock.restart();
                    } else {
                        activeInputBox = None; // Deselect all if clicking elsewhere
                    }
                }
                if (event.type == sf::Event::TextEntered) {
                    if (activeInputBox != None) {
                        string& currentInput = inputStrings[activeInputBox];
                        sf::Text& activeText = inputTexts[activeInputBox];

                        char typedChar = static_cast<char>(event.text.unicode);
                        if (isprint(typedChar)) {
                            switch (activeInputBox) {
                                case Latitude:
                                    if (typedChar == '-' && currentInput.empty()) {
                                        currentInput += typedChar;
                                    }
                                        // Allow one period if it doesn't already exist and field isn't empty
                                    else if (!currentInput.empty() && typedChar == '.' && currentInput.find('.') == std::string::npos) {
                                        currentInput += typedChar;
                                    }
                                        // Digits only, cap length, cap digits before decimal pt (accounting for - sign)
                                    else if (currentInput.size() < 10 && isdigit(typedChar) && (currentInput.find('.') != std::string::npos ||
                                            (currentInput[0] != '-' && currentInput.size() < 2) || (currentInput[0] == '-') && currentInput.size() < 3)) {
                                        currentInput += typedChar;
                                    }
                                    break;
                                case Longitude:
                                    if (typedChar == '-' && currentInput.empty()) {
                                        currentInput += typedChar;
                                    }
                                        // Allow one period if it doesn't already exist
                                    else if (!currentInput.empty() && typedChar == '.' && currentInput.find('.') == std::string::npos) {
                                        currentInput += typedChar;
                                    }
                                        // Digits only, cap length, cap digits before decimal pt (accounting for - sign)
                                    else if (currentInput.size() < 11 && isdigit(typedChar) && (currentInput.find('.') != std::string::npos ||
                                            (currentInput[0] != '-' && currentInput.size() < 3) || (currentInput[0] == '-') && currentInput.size() < 4)) {
                                        currentInput += typedChar;
                                    }
                                    break;
                                case MaxPrice:
                                    if (isdigit(typedChar) && currentInput.size() < 8)
                                        currentInput += typedChar;
                                    break;
                                case DisplayCount:
                                    if (isdigit(typedChar) && currentInput.size() < 2)
                                        currentInput += typedChar;
                                    break;
                                default:
                                    break;
                            }
                        } else if (event.text.unicode == 8 && !currentInput.empty()) { // Backspace
                            currentInput.pop_back();
                        }
                        activeText.setString(currentInput); // Update displayed text
                    }
                }
                if (event.type == sf::Event::MouseWheelScrolled) {
                    if (displayed) {
                        handleScroll(event, listings.size());
                    }
                }
            }
            // Draw UI
            renderUI();
        }
    } catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }
}


void Window::renderUI() {
    win.clear(sf::Color::Black);
    // Draw static elements (title, labels, buttons, etc.)
    win.draw(titleText);
    resetButton.draw(win);
    runButton.draw(win);

    win.draw(errorText);
    win.draw(sortText);

    win.draw(latLocation);
    win.draw(longLocation);
    win.draw(labelMaxPrice);
    win.draw(labelSortMethod);
    win.draw(labelSortParam);
    win.draw(labelDisplayCount);

    win.draw(inputBoxLat);
    win.draw(inputBoxLong);
    win.draw(inputBoxMaxPrice);
    win.draw(inputBoxDisplayCount);

    win.draw(outputList);

    // Draw the dropdown buttons
    win.draw(methodDropdownButton);
    win.draw(methodDropdownButtonText);
    win.draw(paramDropdownButton);
    win.draw(paramDropdownButtonText);

    // Draw the dropdown options if dropdown is open
    if (isMethodDropdownOpen) {
        for (const auto& sortMethodOption : sortMethodOptions) {
            win.draw(sortMethodOption);
        }
        for (const auto& methodText : sortMethodOptionTexts) {
            win.draw(methodText);
        }
    }
    if (isParamDropdownOpen) {
        for (const auto& sortParamOption : sortParamOptions) {
            win.draw(sortParamOption);
        }
        for (const auto& paramText : sortParamOptionTexts) {
            win.draw(paramText);
        }
    }

    if (cursorClock.getElapsedTime().asSeconds() > 0.5f) {
        cursorVisible = !cursorVisible;
        cursorClock.restart();
    }
    if (activeInputBox != None) {
        const sf::Text& activeText = inputTexts[activeInputBox];
        cursor.setPosition(activeText.getGlobalBounds().left + activeText.getGlobalBounds().width + 1,
                           inputBoxHeights[activeInputBox] + 6); // Hard-coded for input box. Could add map to store box breadth
        if (cursorVisible) {
            win.draw(cursor); // Only draw the cursor for the active input field
        }
    }
    for (const auto& [type, text] : inputTexts) {
        win.draw(text);
    }

    win.draw(outputList);
    win.draw(scrollBar); // Draw the scroll bar
    win.display();

}


void Window::resetParameters() {
    lat = lon = 0;
    maxPrice = 0;
    dispCt = 0;
    methodOption = paramOption = -1; // Reset dropdown options

    // Can also clear the output list or reset it here
    for (auto& [type, text] : inputTexts) {
        inputStrings[type] = "";
        text.setString("");
    }
    errorText.setString(""); // Clear any error messages
    sortText.setString("");
    paramDropdownButtonText.setString("<Select One>");
    methodDropdownButtonText.setString("<Select One>");
    isParamDropdownOpen = false;
    isMethodDropdownOpen = false;
    displayed = false;

    renderUI(); // Redraw UI
}

void Window::displayListings(const vector<Listing>& list, int n) {
    const float padding = 10.0f;
    float yOffset = outputList.getPosition().y + padding - scrollOffset.y;
    sf::Font font = menuFont; // Use your existing font

    for (size_t i = 0; i < min(n, (int)list.size()); ++i) {
        if (yOffset > outputList.getPosition().y + outputList.getSize().y) break; // Stop if outside view
        if (yOffset + 30.0f >= outputList.getPosition().y) { // Render only if visible
            sf::Text listingText;
            listingText.setFont(font);
            listingText.setString(list[i].toString()); // Implement `toString()` in `Listing`
            listingText.setCharacterSize(14);
            listingText.setFillColor(sf::Color::White);
            listingText.setPosition(outputList.getPosition().x + 10, yOffset);
            win.draw(listingText);
        }
        yOffset += 30.0f + padding;
    }
}

void Window::handleScroll(const sf::Event& event, size_t totalListings) {
    const float maxScrollOffset = max(0.0f, totalListings * 40.0f - outputList.getSize().y); // 40 is the height per listing
    if (event.type == sf::Event::MouseWheelScrolled) {
        if (outputList.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(win)))) {
            scrollOffset.y += -event.mouseWheelScroll.delta * scrollSpeed;
            scrollOffset.y = max(0.0f, min(scrollOffset.y, maxScrollOffset));
            scrollBar.setSize(sf::Vector2f(scrollBar.getSize().x, outputList.getSize().y * (outputList.getSize().y / (totalListings * 40.0f))));
            scrollBar.setPosition(scrollBar.getPosition().x, outputList.getPosition().y + (scrollOffset.y / maxScrollOffset) * (outputList.getSize().y - scrollBar.getSize().y));
        }
    }
}

sf::Text renderText(const string& msg, const sf::Font& font, int size, sf::Color color, bool bold, bool underlined) {
    sf::Text text(msg, font, size);
    if (bold)
        text.setStyle(sf::Text::Bold);
    if (underlined)
        text.setStyle(sf::Text::Underlined);
    text.setFillColor(color);
    return text;
}

InputBoxType getNextInputBox(InputBoxType curr) {
    if (curr == DisplayCount || curr == None)
        return Latitude;
    return static_cast<InputBoxType>(curr + 1);
}