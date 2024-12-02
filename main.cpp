/******************************
 * File: main.cpp
 * Purpose: This file contains the driver code for the whole program and runs the console interface to use the application.
 * Authors: Ian Zhou, Phoenix Cushman, Matthew Golden.
 * Created: 11/30/2024
 ******************************/

#include <iostream>
#include "dev.h"
#include "util.h"
#include "introsort.h"
#include "timsort.h"

int main(){
    
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "     COP3530 Project 3 - Bee's Eye View" << std::endl;
    std::cout << " By: Ian Zhou, Phoenix Cushman, Matthew Golden" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;

    // TODO:
    cout << "Test input run: \n";
    const int max_price = 211;
    vector<Listing> listings;

    if (!getListingsByPrice(listings, max_price, "data/air-bnb-sample.json")) {
        return -1;
    }

    for (const auto &listing : listings) {
        cout << "Listing " << listing.name << endl;
        cout << "Price: " << listing.price << endl;
        cout << "Days available: " << listing.availability << endl;
        cout << "Coords: (" << listing.coord_lon << ", " << listing.coord_lat << ")\n\n";
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