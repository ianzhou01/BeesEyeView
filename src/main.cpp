/******************************
 * File: main.cpp
 * Purpose: This file contains the driver code for the whole program and runs the console interface to use the application.
 * Authors: Ian Zhou, Phoenix Cushman, Matthew Golden.
 * Created: 11/30/2024
 ******************************/

#include <algorithm>
#include <float.h>
#include <iostream>
#include "util.h"
#include "introsort.h"
#include "timsort.h"
using namespace std;

int main(){
    
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "     COP3530 Project 3 - Bee's Eye View" << std::endl;
    std::cout << " By: Ian Zhou, Phoenix Cushman, Matthew Golden" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;

    // TODO:
    cout << "Enter the location to search from (latitude longitude): ";
    double latitude, longitude;
    cin >> latitude >> longitude;
    while (cin.fail() || latitude < -90 || latitude > 90 || longitude < -180 || longitude > 180) {
        cout << "\nInvalid input, please enter a valid location: ";
        cin.clear();
        cin.ignore(DBL_MAX, '\n');
        cin >> latitude >> longitude;
    }

    cout << "Enter the radius to search from: ";
    double search_radius;
    cin >> search_radius;
    while (cin.fail() || search_radius < 0 || search_radius > 360) {
        cout << "\nInvalid input, please enter a valid radius to search: ";
        cin.clear();
        cin.ignore(DBL_MAX, '\n');
        cin >> search_radius;
    }

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

    if (!getListingsByDistance(listings, longitude, latitude, search_radius, "../data/air-bnb-sample.json")) {
         return -1;
    }
    if (!getListingsByPrice(listings, max_price, "../data/air-bnb-sample.json")) {
        return -1;
    }
    if (listings.empty()) {
        cout << "No listings found. :(\n";
        return 0;
    }

    for (const auto &listing : listings) {
        cout << "Name: " << listing.name << endl;
        cout << "Rate: $" << listing.price << endl;
        cout << "Days available: " << listing.availability << endl;
        cout << "Coords: (" << listing.coord_lon << ", " << listing.coord_lat << ")\n\n";
    }

    cout << "What property would you like to sort by?" << endl
    << "1. name" << endl
    << "2. price" << endl
    << "3. distance" << endl
    << "Enter your selection (1, 2, or 3): ";

    string property_choice;
    cin >> property_choice;
    while (property_choice != "1" && property_choice != "2") {
        cout << "\nPlease choose a valid option." << endl
        << "1. name" << endl
        << "2. price" << endl
        << "3. distance" << endl
        << "Enter your selection (1, 2, or 3): ";
        cin >> property_choice;
    }

    cout << "How would you like to sort your data?" << endl
    << "1. timsort" << endl
    << "2. introsort" << endl
    << "Enter your selection (1 or 2): ";

    string sort_choice;
    cin >> sort_choice;
    while (sort_choice != "1" && sort_choice != "2") {
        cout << "\nPlease choose a valid option." << endl
        << "1. timsort" << endl
        << "2. introsort" << endl
        << "Enter your selection (1 or 2): ";
        cin >> sort_choice;
    }

    if (sort_choice == "1") {

    }
    else if (sort_choice == "2") {

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