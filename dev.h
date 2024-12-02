#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <regex> //we will be using regex for format verification and other text purposes. Use this website to verify regex strings https://regex101.com/
#include "cmake-build-debug/_deps/rapidjson-src/include/rapidjson/rapidjson.h"
using namespace std;
/*
Data element example:
{
    "id": 40438184,
    "name": "90 m2 atypical design close to the SACRE COEUR - Professional Cleaning",
    "host_id": 312794780,
    "neighbourhood": "Buttes-Montmartre",
    "room_type": "Entire home/apt",
    "column_10": 210,
    "minimum_nights": 1,
    "number_of_reviews": 3,
    "last_review": "2020-01-11",
    "reviews_per_month": 0.56,
    "calculated_host_listings_count": 1,
    "availability_365": 0,
    "updated_date": "2020-06-11",
    "city": "Paris",
    "column_19": "France",
    "coordinates": {"lon": 2.356893361174352, "lat": 48.889171083723596},
    "column_20": "France, Paris, Buttes-Montmartre"
}
*/

//Data element class defition (Mimics the format in the actual json file for convinience)
class element {

    //
    // NOTE! The decision to make id values strings instead of integers is temporary and can be discussed and changed later
    //

public:
    string id = "";
    string name = "";
    string host_id = "";
    string neighbourhood = "";
    string room_type = "";
    long column_10 = -1;
    long minimum_nights = -1;
    long number_of_reviews = -1;
    string last_review = "";
    double reviews_per_month = nanf(""); //sets this value to NaN until we initialize it
    int calculated_host_listings_count = -1;
    int availability_365 = -1;
    string updated_date = "";
    string city = "";
    string column_19 = "";
    double coordinates_lon = nanf(""); //sets this value to NaN until we initialize it
    double coordinates_lat = nanf(""); //sets this value to NaN until we initialize it
    string column_20 = "";
    //custom field for our own purposes
    double distance = nanf(""); //sets this value to NaN until we initialize it
};
element parseJsonSingle(string flat);
static bool compareDistance(element e1, element e2);

