cmake_minimum_required(VERSION 3.24)
project(Samuel_Skinner_RPG)

# Use modern C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(..)

# Source files (only .cpp, no .h files)
add_executable(Skinner_SamuelRPG
        main.cpp
        Story.cpp)