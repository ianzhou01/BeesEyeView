#include "util.h"

bool getAvailableListings(vector<Listing>& listings, const int maxPrice, const string& json)  {
    Document doc;
    doc.Parse(json.c_str());

    // Check if JSON is valid
    if (doc.HasParseError()) {
        cerr << "Error parsing JSON!" << endl;
        return false;
    }

    if (doc.HasMember("results") && doc["results"].IsArray()) {
        const Value& results = doc["results"];
        for (SizeType i = 0; i < results.Size(); ++i) {
            const Value& listing = results[i];

            // Check if listing is available
            if (listing.HasMember("availability_365") && listing["availability_365"].GetInt() > 0 &&
                listing.HasMember("column_10") && listing["column_10"].GetInt() <= maxPrice)
            {
                Listing available_listing;
                available_listing.id = listing["id"].GetInt();
                available_listing.name = listing["name"].GetString();
                available_listing.host_id = listing["host_id"].GetInt();
                available_listing.neighbourhood = listing["neighbourhood"].GetString();
                available_listing.room_type = listing["room_type"].GetString();
                available_listing.price = listing["column_10"].GetInt();
                available_listing.minimum_nights = listing["minimum_nights"].GetInt();
                available_listing.num_reviews = listing["number_of_reviews"].GetInt();
                available_listing.last_review_date = listing["last_review"].GetString();
                available_listing.reviews_per_month = listing["reviews_per_month"].GetFloat();
                available_listing.calculated_host_listings_count = listing["calculated_host_listings_count"].GetInt();
                available_listing.availability = listing["availability_365"].GetInt();
                available_listing.updated_date = listing["updated_date"].GetString();
                available_listing.city = listing["city"].GetString();
                available_listing.country = listing["column_19"].GetString();

                // This can potentially be optimized:
                const Value& coords = listing["coordinates"].GetArray();
                available_listing.coord_lon = coords["lon"].GetDouble();
                available_listing.coord_lat = coords["lat"].GetDouble();

                // Add to the result vector
                listings.push_back(available_listing);
            }
        }
    }
    return true;
}