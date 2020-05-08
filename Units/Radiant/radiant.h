//
// Created by kot on 08.05.2020.
//

#ifndef RADIANT_H
#define RADIANT_H
#include "../../unit.h"

class Radiant : public Unit
{
public:
    virtual Unit *itemCopy() = 0;
};


#endif //RADIANT_H
