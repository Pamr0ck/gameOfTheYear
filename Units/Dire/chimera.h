//
// Created by kot on 08.05.2020.
//

#ifndef CHIMERA_H
#define CHIMERA_H

#include "dire.h"

class Chimera : public Dire {
public:
    Chimera(){
        name = "Chimera";
        characteristics->setAll(100, 80, 50);
    };
    std::string getName() {return name;}
    Unit *itemCopy(){
        return new Chimera(*this);
    }
};

#endif //CHIMERA_H
