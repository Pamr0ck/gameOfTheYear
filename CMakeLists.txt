cmake_minimum_required(VERSION 3.15)
project(gameOfTheYear)

set(CMAKE_CXX_STANDARD 20)

add_executable(gameOfTheYear main.cpp field.h field.cpp libraries.h Units/unit.cpp Units/unit.h characteristics.cpp characteristics.h observer.h subject.cpp subject.h moveMediator.h Units/Melee/ork.h Units/Support/witch.h Units/Range/chimera.h Units/Melee/knight.h Units/Support/dryad.h Units/Range/dragon.h Units/Factory/unitFactory.h Units/Melee/melee.h Units/Range/range.h Units/Support/support.h Units/Factory/direFactory.h Units/Factory/radiantFactory.h)