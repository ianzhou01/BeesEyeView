# BeesEyeView
An All-purpose Airbnb Finder

To run this code, clone this repo into CLion (make sure you clone the main branch). Then, ensure your working directory is set to src/. Download SFML 2.5.1 and attach the full SFML folder to your root directory, or modify CMakeLists.txt accordingly to reflect the file path to your SFML folder (see comments in CMakeLists.txt). Ensure you choose CMakeLists.txt included from the repo, then build and run the project according to these specifications. 

What BeesEyeView does:
- Parses through 1.4 million current AirBnB entries (sourced from OpenDataSoft) upon user query.
    - Automatically validates AirBnB listings based on price limit and availability.
- Calculates global distance to user using the haversine function for each listing.
- Employs specialized Introsort/Timsort hybrid sorting algorithms to determine closest N listings to user.
- Returns results sorted by price or distance, by user choice.

Requires:
- CMake v3.27 (or higher)
- C++ 17 (specified in CMakeLists.txt)
- SFML 2.5.1 (if higher version, modify CMakeLists.txt accordingly)
- This project was developed with the MinGW-W64 g++ compiler (x86_64-win32-seh-rev0, version 7.3.0). Later g++ versions of the same configuration should also work.