# Don't modify
cmake_minimum_required(VERSION 3.27)
project(AirBnB)

set(CMAKE_CXX_STANDARD 17)

add_executable(AirBnB
        src/main.cpp
        src/util.cpp
        src/window.cpp
        src/introsort.cpp
        src/timsort.cpp
        src/button.cpp
)

# Don't modify
target_link_libraries(AirBnB sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
set(SFML_STATIC_LIBRARIES TRUE)

# Modify if needed
set(SFML_DIR C:/SFML/lib/cmake/SFML)

# Don't modify (unless you are using a different version of SFML, which might not be supported)
find_package(SFML 2.5.1 COMPONENTS system window graphics audio network REQUIRED)

# Modify if needed
include_directories(c:/SFML/include/SFML)
