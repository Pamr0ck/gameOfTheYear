//
// Created by kot on 08.05.2020.
//

#ifndef DIRE_H
#define DIRE_H
#include "../../unit.h"

class Dire : public Unit
{
public:
    virtual Unit *itemCopy() = 0;
};

#endif //DIRE_H
