//
// Created by kot on 08.05.2020.
//

#ifndef DRYAD_H
#define DRYAD_H
#include "Support.h"

class Dryad : public Support
{
public:
    // todo heal if health < 10 % every 3th turn  on 30% of hp
    Dryad()
    {
        name = "Dryad";
        characteristics->setAll(20, 40, 45);
    };
    std::string getName() {return name;}
    Unit *itemCopy(){
        return new Dryad(*this);
    }
};

#endif //DRYAD_H
