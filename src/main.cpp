/******************************
 * File: main.cpp
 * Purpose: This file contains the driver code for the whole program and runs the console interface to use the application.
 * Authors: Ian Zhou, Phoenix Cushman, Matthew Golden.
 * Created: 11/30/2024
 ******************************/

#include <iostream>
#include "util.h"
#include "introsort.h"
#include "timsort.h"
#include <cfloat>
#include <iomanip>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(){
    cout << "------------------------------------------------" << endl;
    cout << "     COP3530 Project 3 - Bee's Eye View" << endl;
    cout << " By: Ian Zhou, Phoenix Cushman, Matthew Golden" << endl;
    cout << "------------------------------------------------" << endl;

    // TODO:
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

    cout << "Enter your maximum room rate ($1 - $100,000): $";
    int max_price;
    cin >> max_price;
    while (max_price < 1 || max_price > 100000) {
        cout << "\nInvalid input, please enter a number within the given range ($1 - $100,000): $";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cin >> max_price;
        cout << endl;
    }
    vector<Listing> listings;
    if (!getListings(listings, max_price,
                     "data/air-bnb-sample.json", {lat, lon})) {
        return -1;
    }
    if (listings.empty()) {
        cout << "No listings found. :(\n";
        return 0;
    }

    // Get sort parameter
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

    // Get sort method
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

    int numListings;
    cout << "How many entries to display? Enter a number:";
    cin >> numListings;
    while (cin.fail() || numListings < 0) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Enter a valid number!\nHow many entries to display? Enter a number:";
        cin >> numListings;
    }

    // Sort data
    // Default distance comparator
    auto distComp = [](const Listing& a, const Listing& b)-> bool {
        return a.distance < b.distance;
    };

    if (sort_choice == "1") {
        // Use Timsort (implement timer feature later)

    }
    else if (sort_choice == "2") {
        // Use Introsort (implemented timer)
        auto start = high_resolution_clock::now();
        intro::sort(listings, listComp(distComp));
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);

        cout << "\nSorted through " << listings.size() << " available listings in " << duration.count() << " ms\n\nListings:\n\n";
        // Note: we don't need to sort by distance again, so property_choice of 1 is trivial
        if (property_choice == "2") {
            // Sort top 10 by price
            auto priceComp = [](const Listing& a, const Listing& b)-> bool {
                return a.price < b.price;
            };
            // Sort first numListings elements
            intro::sort(listings, 0, min(numListings, (int)listings.size()),
                        listComp(priceComp));
        }

        for (int i = 0; i < min(numListings, (int)listings.size()); ++i) {
            cout << "Name: " << listings[i].name << endl;
            cout << "Rate: $" << listings[i].price << endl;
            cout << "Days available: " << listings[i].availability << endl;
            cout << fixed << setprecision(4) << "Distance: " << listings[i].distance << " km\n\n";
        }
    }
    else {
        cerr << "Something went terribly wrong. What a bother." << endl;
        return -1;
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