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
#include <iomanip>

int main(){
    cout << "------------------------------------------------" << endl;
    cout << "     COP3530 Project 3 - Bee's Eye View" << endl;
    cout << " By: Ian Zhou, Phoenix Cushman, Matthew Golden" << endl;
    cout << "------------------------------------------------" << endl;

    cout << "Enter your coordinates below in degrees (N and E positive, W and S negative):\n"
            "Latitude:";
    double lat, lon;
    cin >> lat;
    while (cin.fail()) {
        cin.clear(); // Reset error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a valid value!\nLatitude:";
        cin >> lat;
    }
    cout << "Longitude:";
    cin >> lon;
    while (cin.fail()) {
        cin.clear(); // Reset error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a valid value!\nLongitude:";
        cin >> lon;
    }

    cout << "Enter your maximum room rate: $";
    int max_price;
    cin >> max_price;
    while (cin.fail()) {
        cin.clear(); // Reset error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a valid value!\nEnter your maximum room rate: $";
        cin >> max_price;
    }

    vector<Listing> listings;

    if (!getListingsByPrice(listings, max_price,
                            "data/air-bnb-sample.json", {lat, lon})) {
        return -1;
    }
    if (listings.empty()) {
        cout << "No listings found. :(\n";
        return 0;
    }

    auto distComp = [](const Listing& a, const Listing& b)-> bool {
        return a.distance < b.distance;
    };

    intro::sort(listings, listComp(distComp));

    cout << "Would you like results sorted by cheapest or closest (Y/y for cheapest, anything else for closest)";
    char priceSort;
    cin >> priceSort;
    cin.clear(); // Reset error flags
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer

    if (priceSort == 'Y' || priceSort == 'y') {
        auto priceComp = [](const Listing& a, const Listing& b)-> bool {
            return a.price < b.price;
        };
        // Sort first 10 elements, or whatever's in there
        intro::sort(listings, 0, min(10, (int)listings.size()),
                    listComp(priceComp));
    }

    for (int i = 0; i < min(10, (int)listings.size()); ++i) {
        cout << "Name: " << listings[i].name << endl;
        cout << "Rate: $" << listings[i].price << endl;
        cout << "Days available: " << listings[i].availability << endl;
        cout << fixed << setprecision(4) << "Distance: " << listings[i].distance << " km\n";
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