/******************************
 * File: main.cpp
 * Purpose: This file contains the driver code for the whole program and runs the console interface to use the application.
 * Authors: Ian Zhou, Phoenix Cushman, Matthew Golden.
 * Created: 11/30/2024
 ******************************/

#pragma once
#include <iostream>
#include "util.h" // Listing class and Json parsing
#include "introsort.h"
#include "timsort.h"
#include <cfloat>
#include <iomanip>
#include <chrono> // For timing functions
#include <SFML/Graphics.hpp>
int main(){
    cout << "------------------------------------------------" << endl;
    cout << "     COP3530 Project 3 - Bee's Eye View" << endl;
    cout << " By: Ian Zhou, Phoenix Cushman, Matthew Golden" << endl;
    cout << "------------------------------------------------" << endl;

    // TODO:
    //Getting initial location data for distance calculations
    cout << "Enter the location to search from (lat lon):";
    double lat, lon;
    cin >> lat >> lon;
    while (cin.fail() || lat < -90 || lat > 90 || lon < -180 || lon > 180) {
        cout << "\nInvalid input, please enter a valid location!\nEnter the location to search from (lat lon):";
        cin.clear();
        cin.ignore(DBL_MAX, '\n');
        cin >> lat >> lon;
    }

//    cout << "Enter the radius to search from:";
//    double search_radius;
//    cin >> search_radius;
//    while (cin.fail() || search_radius < 0 || search_radius > 360) {
//        cout << "\nInvalid input, please enter a valid radius to search:";
//        cin.clear();
//        cin.ignore(DBL_MAX, '\n');
//        cin >> search_radius;
//    }

    //Gets max room rate user is willing to pay
    cout << "Enter your maximum room rate ($1 - $250,000,000): $";
    int max_price;
    cin >> max_price;
    while (max_price < 1 || max_price > 250000000) {
        cout << "\nInvalid input, please enter a number within the given range ($1 - $250,000,000): $";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cin >> max_price;
        cout << endl;
    }
    vector<Listing> listings;

    for (int i=1; i<=40; ++i) {
        if (!getListings(listings, max_price,
                         "../data/all_data/split_" + to_string(i) + ".json",
                         {lat, lon})) {
            return -1;
        }
    }

    if (listings.empty()) {
        cout << "No listings found. :(\n";
        return 0;
    }

    // Gets sort parameter
    cout << "What property would you like to sort by?" << endl
         << "1. distance" << endl
         << "2. price" << endl
         << "Enter your selection (1 or 2):";

    string property_choice;
    cin >> property_choice;
    while (property_choice != "1" && property_choice != "2" && property_choice != "3") {
        cout << "\nPlease choose a valid option." << endl
             << "1. distance" << endl
             << "2. price" << endl
             << "Enter your selection (1 or 2):";
        cin >> property_choice;
    }

    // Gets sort method
    cout << "How would you like to sort your data?" << endl
         << "1. timsort" << endl
         << "2. introsort" << endl
         << "Enter your selection (1 or 2):";

    string sort_choice;
    cin >> sort_choice;
    while (sort_choice != "1" && sort_choice != "2") {
        cout << "\nPlease choose a valid option." << endl
             << "1. timsort" << endl
             << "2. introsort" << endl
             << "Enter your selection (1 or 2):";
        cin >> sort_choice;
    }

    //Gets the number of entries to display
    int numListings;
    cout << "How many entries to display? Enter a number (1 - 100):";
    cin >> numListings;
    while (cin.fail() || numListings < 0 || numListings > 100) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Enter a valid number!\nHow many entries to display? Enter a number (1 - 100):";
        cin >> numListings;
    }

    // Sort data
    // Default distance comparator
    auto distComp = [](const Listing& a, const Listing& b)-> bool {
        return a.distance < b.distance;
    };

    if (sort_choice == "1") {
        // Use Timsort (implemented timer)
        auto start = chrono::high_resolution_clock::now();
        tim::sort(listings, listComp(distComp));

        // Note: we don't need to sort by distance again, so property_choice of 1 is trivial
        if (property_choice == "2") {
            // Sort top numListings by price
            auto priceComp = [](const Listing& a, const Listing& b)-> bool {
                return a.price < b.price;
            };
            // Sort first numListings elements
            tim::sort(listings, listComp(priceComp));
        }

        //Output time for sorts
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

        cout << "\nSorted through " << listings.size() << " available listings in " << duration.count() << " ms\n\nListings:\n\n";
    }
    else if (sort_choice == "2") {
        // Use Introsort (implemented timer)
        auto start = chrono::high_resolution_clock::now();
        intro::sort(listings, listComp(distComp));

        // Note: we don't need to sort by distance again, so property_choice of 1 is trivial
        if (property_choice == "2") {
            // Sort top numListings by price
            auto priceComp = [](const Listing& a, const Listing& b)-> bool {
                return a.price < b.price;
            };
            // Sort first numListings elements
            intro::sort(listings, 0, min(numListings, (int)listings.size()),
                        listComp(priceComp));
        }

        //Output time for sorts
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

        cout << "\nSorted through " << listings.size() << " available listings in " << duration.count() << " ms\n\nListings:\n\n";
    }
    else {
        cerr << "Something went terribly wrong. What a bother." << endl;
        return -1;
    }

    //Output results
    for (int i = 0; i < min(numListings, (int)listings.size()); ++i) {
        cout << "Name: " << listings[i].name << endl;
        cout << "Rate: $" << listings[i].price << endl;
        cout << "Days available: " << listings[i].availability << endl;
        cout << fixed << setprecision(4) << "Distance: " << listings[i].distance << " km\n\n";
    }

    // do some sort of user interface to ask for parameters
    //
    // run file i/o to grab the sample file
    // repeatedly call the parseJsonSingle function to parse all the elements and push them all to a element vector
        // filter out unnecessary elements as we go
    // run the sorting algorithm on the vector
    //
    // return the top k results based off the user parameters in some sort of nifty looking interface

    return 0;
}
