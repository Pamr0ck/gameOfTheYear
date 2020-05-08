cmake_minimum_required(VERSION 3.15)
project(gameOfTheYear)

set(CMAKE_CXX_STANDARD 20)

add_executable(gameOfTheYear main.cpp field.h field.cpp libraries.h unit.cpp unit.h characteristics.cpp characteristics.h observer.h subject.cpp subject.h moveMediator.h Units/Dire/ork.h Units/Dire/dire.h Units/Dire/witch.h Units/Dire/chimera.h Units/Radiant/radiant.h Units/Radiant/knight.h Units/Radiant/dryad.h Units/Radiant/dragon.h)