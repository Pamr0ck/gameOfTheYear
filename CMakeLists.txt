cmake_minimum_required(VERSION 3.15)
project(gameOfTheYear)

set(CMAKE_CXX_STANDARD 20)

add_executable(gameOfTheYear
        main.cpp Field/field.h Field/field.cpp libraries.h
        Units/unit.cpp Units/unit.h
        Units/characteristics.cpp Units/characteristics.h
        observer.h subject.cpp subject.h moveMediator.h
        Units/Melee/ork.h Units/Support/witch.h
        Units/Range/chimera.h Units/Melee/knight.h
        Units/Support/dryad.h Units/Range/dragon.h
        Units/Factory/unitFactory.h Units/Melee/melee.h
        Units/Range/range.h Units/Support/support.h
        Units/Factory/direFactory.h Units/Factory/radiantFactory.h
        Landscape/proxy.cpp Landscape/proxy.h
        NeutralObject/neutralObj.h NeutralObject/weapon.h
        NeutralObject/armor.h NeutralObject/elixir.h NeutralObject/curse.h NeutralObject/context.h Field/fieldItem.cpp Field/fieldItem.h Base/composite.h)