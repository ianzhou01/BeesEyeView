/******************************
 * File: dev.cpp
 * Purpose: This file contains helper functions, various methods, and class definitions that the main program utilizes
 * Authors: Ian Zhou, Phoenix Cushman, Matthew Golden.
 * Created: 11/30/2024
 ******************************/
#include "dev.h"
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

//This is the regex verification pattern for one of the json elements in the input files
//regex json_element_format = regex("^{\"id\": [0-9]{8}, \"name\": \".*?\", \"host_id\": [0-9]{9}, \"neighbourhood\": \".*?\", \"room_type\": \".*?\", \"column_10\": [0-9]+?, \"minimum_nights\": [0-9]+?, \"number_of_reviews\": [0-9]+?, \"last_review\": \"[0-9]{4}-[0-9]{2}-[0-9]{2}\", \"reviews_per_month\": [0-9]+?.[0-9]+?, \"calculated_host_listings_count\": [0-9]+?, \"availability_365\": [0-9]+?, \"updated_date\": \"[0-9]{4}-[0-9]{2}-[0-9]{2}\", \"city\": \".*?\", \"column_19\": \".*?\", \"coordinates\": {\"lon\": [0-9]+?.[0-9]+?, \"lat\": [0-9]+?.[0-9]+?}, \"column_20\": \".*?\"}$");


///////////////////////////////////////////
//Helper functions and methods
///////////////////////////////////////////

//Returns a new element object containing the data it pulled from the json formatted input string. Should be formatted as {"id": ********, "name": "*", etc.}
//element parseJsonSingle(string flat) {
//    element e;
//    if (!regex_match(flat, json_element_format)) { //catch an erroneously formmated input string
//        e.id = "-1"; //return a -1 in the id as an error code
//    }
//    else {
//        istringstream line(flat);
//        string input_slice;
//        getline(line, input_slice, ' ');
//        getline(line, input_slice, ',');
//        e.id = input_slice;
//        getline(line, input_slice, '"');
//        getline(line, input_slice, '"');
//        getline(line, input_slice, '"');
//        e.name = input_slice;
//        // .
//        // .
//        // .
//        // continue slicing and copying until we've parsed all the fields
//    }
//    return e;
//}

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