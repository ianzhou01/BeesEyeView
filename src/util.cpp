/******************************
 * File: util.cpp
 * Purpose: This file defines attributes of the listing struct and utility methods
 * Authors: Ian Zhou, Phoenix Cushman
 * Created: 11/30/2024
 ******************************/

#include "util.h"

// Defaults to distance comparison
bool Listing::operator<(const Listing &other) const {
    return (this->distance < other.distance);
}

bool Listing::operator>(const Listing &other) const {
    return (this->distance > other.distance);
}

string Listing::toString() const {
    ostringstream oss;
    oss << fixed << setprecision(3)
        << "===AVAILABLE===\nRoom type: " << room_type
        << "\nPrice: $" << price
        << "\nLocation: " << city << ", " << country
        << "\nAvailability: " << availability << " days\n";

    if (distance >= 1)
        oss << distance << " km from you";
    else
        oss << distance / 1000 << " m from you";

    return oss.str();
}

double toRadians(double degree) {
    return degree * (M_PI / 180.0);
}

double haversine(double lat1, double lon1, double lat2, double lon2) {
    lat1 = toRadians(lat1);
    lon1 = toRadians(lon1);
    lat2 = toRadians(lat2);
    lon2 = toRadians(lon2);

    // difference in coordinates
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;

    // Use formula
    double a = sin(dlat / 2) * sin(dlat / 2) +
               cos(lat1) * cos(lat2) *
               sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    // Distance in km
    return R * c;
}