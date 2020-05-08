//
// Created by kot on 08.05.2020.
//

#ifndef DRAGON_H
#define DRAGON_H
#include "radiant.h"

class Dragon : public Radiant{
public:
    Dragon()
    {
        name = "Dragon";
        characteristics->setAll(120, 10, 90);
    };
    std::string getName() {return name;}
    Unit *itemCopy(){
        return new Dragon(*this);
    }
};

#endif //DRAGON_H
