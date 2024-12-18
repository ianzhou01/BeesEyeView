/******************************
 * File: util.h
 * Purpose: This file contains the listing struct and declares utility methods
 * Authors: Ian Zhou, Phoenix Cushman
 * Created: 11/30/2024
 ******************************/

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <functional>
#include <iomanip>

// NOTE: check header path
#include "../include/rapidjson/document.h"
#include "../include/rapidjson/filereadstream.h"
#include "../include/rapidjson/reader.h"

using namespace rapidjson;
using namespace std;

const double R = 6371.0; // Earth's radius in km

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

    // Defaults to distance comparison (unused currently)
    bool operator<(const Listing& other) const;
    bool operator>(const Listing& other) const;
    [[nodiscard]] string toString() const;
};


double toRadians(double degree);
double haversine(double lat1, double lon1, double lat2, double lon2);