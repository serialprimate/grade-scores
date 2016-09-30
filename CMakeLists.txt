# CMake build configuration.

# Generate makefiles with:
# $ rm -rf build && mkdir build && cd build && cmake -Wdev --warn-unitialized -D CMAKE_BUILD_TYPE=DEBUG -D CMAKE_CXX_COMPILER=g++ -D CMAKE_C_COMPILER=gcc -D CMAKE_INSTALL_PREFIX=./install -G "Unix Makefiles" -D CMAKE_VERBOSE_MAKEFILE=TRUE ..

cmake_minimum_required(VERSION 2.8.9)

project(GradeScores CXX C)

# Configure Toolchain

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -pedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

# Find Dependencies

# Show CMake output for configuring boost
SET(Boost_DEBUG OFF)
SET(Boost_USE_MULTITHREAD ON)

FIND_PACKAGE(Boost COMPONENTS unit_test_framework)

if(Boost_FOUND)
    # no auto linking
    add_definitions("-DBOOST_ALL_NO_LIB")
    # dynamic linking
    add_definitions("-DBOOST_ALL_DYN_LINK")
endif(Boost_FOUND)

# Build Product Artifacts

add_subdirectory("library/grade")
add_subdirectory("application/grade-scores")

# Build Testing Artifacts

enable_testing()
add_subdirectory("test/library/grade")
add_subdirectory("test/application/grade-scores")

