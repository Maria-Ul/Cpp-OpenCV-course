cmake_minimum_required(VERSION 3.23)
project(Cpp)
#project(Cpp C CXX)

set(CMAKE_CXX_STANDARD 14)

SET(Boost_INCLUDE_DIR /Users/mariaulanova/CLionProjects/boost_1_80_0)
    FIND_PACKAGE(Boost)
IF (Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
ENDIF()

add_executable(Cpp Ex3/paraxial.cpp Ex3/lens.cpp  Ex3/surface.cpp Ex3/spherical_surface.cpp Ex3/second_main.cpp)