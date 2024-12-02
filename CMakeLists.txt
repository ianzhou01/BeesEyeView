cmake_minimum_required(VERSION 3.27)
project(AirBnB)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)

FetchContent_Declare(
        rapidjson
        GIT_REPOSITORY https://github.com/Tencent/rapidjson
        GIT_TAG master
)

FetchContent_MakeAvailable(rapidjson)

add_executable(AirBnB
        src/main.cpp
        src/util.cpp
)