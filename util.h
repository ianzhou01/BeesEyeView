#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include "include/rapidjson-src/include/rapidjson/document.h"
#include "include/rapidjson-src/include/rapidjson/filereadstream.h"
#include "include/rapidjson-src/include/rapidjson/reader.h"

using namespace rapidjson;
using namespace std;

struct Listing {
    // Items are written in the order they appear in the JSON files
    int id;
    string name;
    int host_id;
    string neighbourhood;
    string room_type;
    int price = -1; // written in JSON as column_10
    int minimum_nights = -1;
    int num_reviews = -1;
    string last_review_date;
    float reviews_per_month = nanf(""); //sets this value to NaN until we initialize it
    int calculated_host_listings_count = -1;
    int availability = -1;
    string updated_date; // We can consider deleting this
    string city;
    string country; // written in JSON as column_19
    double coord_lon = nanf(""); //sets this value to NaN until we initialize it
    double coord_lat = nanf(""); //sets this value to NaN until we initialize it

    //custom field for our own purposes
    double distance = nanf(""); //sets this value to NaN until we initialize it
};

bool getListingsByPrice(vector<Listing>& listings, const int maxPrice, const string& fileName);

