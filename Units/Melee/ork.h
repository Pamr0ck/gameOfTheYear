//
// Created by kot on 08.05.2020.
//

#ifndef ORK_H
#define ORK_H

#include "melee.h"
class Ork : public Melee {
public:
    Ork()
    {
        name = "Ork";
        characteristics->setAll(60, 15, 5);
    };
    std::string getName() {return name;}
    Unit *itemCopy(){
        return new Ork(*this);
    }
};

#endif //ORK_H
