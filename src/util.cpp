#include "util.h"

// Defaults to distance comparison
bool Listing::operator<(const Listing &other) const {
    return (this->distance < other.distance);
}

bool Listing::operator>(const Listing &other) const {
    return (this->distance > other.distance);
}

bool getAllListings(vector<Listing>& listings, const int maxPrice,
                    const vector<string>& files, const pair<double, double>& coords) {
    int counter = 0;
    for (const string &fileName : files) {
        ifstream file(fileName);
        if (!file.is_open()) {
            cerr << "Error opening file: " << fileName << endl;
            return false;
        }

        // Read file into string
        stringstream buffer;
        buffer << file.rdbuf();
        string json = buffer.str();
        file.close();

        // Parse entire Json file
        Document doc;
        doc.Parse(json.c_str());

        // Check if JSON is valid
        if (doc.HasParseError()) {
            cerr << "Invalid JSON file!" << endl;
            return false;
        }

        if (doc.HasMember("results") && doc["results"].IsArray()) {
            const Value &results = doc["results"];
            for (SizeType i = 0; i < results.Size(); ++i) {
                const Value &listing = results[i];

                // Check if listing is available
                if (listing.HasMember("availability_365") && listing["availability_365"].GetInt() > 0 &&
                    listing.HasMember("column_10") && listing["column_10"].GetInt() <= maxPrice &&
                    listing["column_10"].GetInt() != 0) { // Filter out unaffordable, unavailable, and erred listings
                    Listing available_listing;
                    available_listing.id = listing["id"].GetInt();
                    if (listing.HasMember("name") && listing["name"].IsString()) {
                        available_listing.name = listing["name"].GetString();
                    } else {
                        available_listing.name = "N/A"; // Can change
                    }
                    available_listing.host_id = listing["host_id"].GetInt();
                    if (listing.HasMember("neighbourhood") && listing["neighbourhood"].IsString()) {
                        available_listing.neighbourhood = listing["neighbourhood"].GetString();
                    } else {
                        available_listing.neighbourhood = "N/A"; // Can change
                    }
                    if (listing.HasMember("room_type") && listing["room_type"].IsString()) {
                        available_listing.room_type = listing["room_type"].GetString();
                    } else {
                        available_listing.room_type = "N/A"; // Can change
                    }
                    available_listing.price = listing["column_10"].GetInt();
                    available_listing.minimum_nights = listing["minimum_nights"].GetInt();
                    available_listing.num_reviews = listing["number_of_reviews"].GetInt();

                    // These two fields are potentially null
                    if (listing.HasMember("last_review") && listing["last_review"].IsString()) {
                        available_listing.last_review_date = listing["last_review"].GetString();
                    } else {
                        available_listing.last_review_date = "N/A";
                    }
                    if (listing.HasMember("reviews_per_month") && listing["reviews_per_month"].IsString()) {
                        available_listing.reviews_per_month = listing["reviews_per_month"].GetFloat();
                    } else {
                        available_listing.reviews_per_month = nanf(""); // Can change
                    }

                    available_listing.calculated_host_listings_count = listing["calculated_host_listings_count"].GetInt();
                    available_listing.availability = listing["availability_365"].GetInt();
                    if (listing.HasMember("updated_date") && listing["updated_date"].IsString()) {
                        available_listing.updated_date = listing["updated_date"].GetString();
                    } else {
                        available_listing.updated_date = "N/A";
                    }
                    if (listing.HasMember("city") && listing["city"].IsString()) {
                        available_listing.city = listing["city"].GetString();
                    } else {
                        available_listing.city = "N/A";
                    }
                    if (listing.HasMember("column_19") && listing["column_19"].IsString()) {
                        available_listing.country = listing["column_19"].GetString();
                    } else {
                        available_listing.country = "N/A";
                    }
                    available_listing.coord_lon = listing["coordinates"]["lon"].GetDouble();
                    available_listing.coord_lat = listing["coordinates"]["lat"].GetDouble();

                    available_listing.distance = haversine(coords.first,
                                                           coords.second,
                                                           available_listing.coord_lat,
                                                           available_listing.coord_lon);

                    // Add to the result vector
                    listings.push_back(available_listing);
                    ++counter;
                }
            }
        }
    }
    return true;
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