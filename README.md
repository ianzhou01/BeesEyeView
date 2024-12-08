# BeesEyeView
An All-purpose Airbnb Finder

To run this code, clone this repo into CLion (make sure you clone the main branch). Then, ensure your working directory is set to src/. Ensure you choose CMakeLists.txt included from the repo, then build and run the project according to these specifications. 

What this project does:
- Parses through 1.4 million current AirBnB entries (sourced from OpenDataSoft) upon user query.
  - Automatically validates AirBnB listings based on price limit and availability.
- Calculates global distance to user using the haversine function for each listing.
- Employs specialized Introsort/Timsort hybrid sorting algorithms to determine closest N listings to user.
- Returns results sorted by price or distance, by user choice.
