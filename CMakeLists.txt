cmake_minimum_required(VERSION 3.15)
project(gameOfTheYear)

set(CMAKE_CXX_STANDARD 20)

add_executable(gameOfTheYear main.cpp field.h field.cpp libraries.h unit.cpp unit.h)