//
// Created by kot on 08.05.2020.
//

#ifndef RADIANTFACTORY_H
#define RADIANTFACTORY_H
#include "unitFactory.h"
#include "knight.h"
#include "dryad.h"
#include "dragon.h"

class RadiantFactory: public UnitFactory
{
public:
    Melee* createMelee() {return  new Knight();};
    Support* createSupport() {return  new Dryad();}
    Range* createRange() {return new Dragon();}
};

#endif //RADIANTFACTORY_H
