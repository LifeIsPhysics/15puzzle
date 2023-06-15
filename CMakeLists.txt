cmake_minimum_required(VERSION 3.25)
project(15puzzle)

set(CMAKE_CXX_STANDARD 20)

add_executable(15puzzle main.cpp tile.cpp tile.h board.cpp board.h direction.cpp direction.h Random.h Point.cpp Point.h)
