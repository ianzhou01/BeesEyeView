/******************************
 * File: dev.cpp
 * Purpose: This file contains helper functions, various methods, and class definitions that the main program utilizes
 * Authors: Ian Zhou, Phoenix Cushman, Matthew Golden.
 * Created: 11/30/2024
 ******************************/

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <regex> //we will be using regex for format verification and other text purposes. Use this website to verify regex strings https://regex101.com/

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
    std::string id = "";
    std::string name = "";
    std::string host_id = "";
    std::string neighbourhood = "";
    std::string room_type = "";
    long column_10 = -1;
    long minimum_nights = -1;
    long number_of_reviews = -1;
    std::string last_review = "";
    double reviews_per_month = std::nanf(""); //sets this value to NaN until we initialize it
    int calculated_host_listings_count = -1;
    int availability_365 = -1;
    std::string updated_date = "";
    std::string city = "";
    std::string column_19 = "";
    double coordinates_lon = std::nanf(""); //sets this value to NaN until we initialize it
    double coordinates_lat = std::nanf(""); //sets this value to NaN until we initialize it
    std::string column_20 = "";
    //custom field for our own purposes
    double distance = std::nanf(""); //sets this value to NaN until we initialize it
};

//This is the regex verification pattern for one of the json elements in the input files
std::regex json_element_format = std::regex("^{\"id\": [0-9]{8}, \"name\": \".*?\", \"host_id\": [0-9]{9}, \"neighbourhood\": \".*?\", \"room_type\": \".*?\", \"column_10\": [0-9]+?, \"minimum_nights\": [0-9]+?, \"number_of_reviews\": [0-9]+?, \"last_review\": \"[0-9]{4}-[0-9]{2}-[0-9]{2}\", \"reviews_per_month\": [0-9]+?.[0-9]+?, \"calculated_host_listings_count\": [0-9]+?, \"availability_365\": [0-9]+?, \"updated_date\": \"[0-9]{4}-[0-9]{2}-[0-9]{2}\", \"city\": \".*?\", \"column_19\": \".*?\", \"coordinates\": {\"lon\": [0-9]+?.[0-9]+?, \"lat\": [0-9]+?.[0-9]+?}, \"column_20\": \".*?\"}$");


///////////////////////////////////////////
//Helper functions and methods
///////////////////////////////////////////

//Returns a new element object containing the data it pulled from the json formatted input string. Should be formatted as {"id": ********, "name": "*", etc.}
element parseJsonSingle(std::string flat) {
    element e;
    if (!std::regex_match(flat, json_element_format)) { //catch an erroneously formmated input string
        e.id = "-1"; //return a -1 in the id as an error code
    }
    else {
        std::istringstream line(flat);
        std::string input_slice;
        std::getline(line, input_slice, ' ');
        std::getline(line, input_slice, ',');
        e.id = input_slice;
        std::getline(line, input_slice, '"');
        std::getline(line, input_slice, '"');
        std::getline(line, input_slice, '"');
        e.name = input_slice;
        // .
        // .
        // .
        // continue slicing and copying until we've parsed all the fields
    }
    return e;
}

// TODO:
// Write some print debug funcitons to spit out element data, lists, formatting, ect.

// TODO:
// Put the basic quadratic sorts here for debugging and testing

// TODO:
// Write a comparator for each of the main types of fields for the elements

bool compareDistance(element e1, element e2) { //returns true if e1 distance is smaller than e2 distance.
    if (e1.distance < e2.distance) {
        return true;
    }
    else {
        return false;
    }
}
// .
// .
// .
// continue other comparators here.