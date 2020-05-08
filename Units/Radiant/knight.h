//
// Created by kot on 08.05.2020.
//

#ifndef KNiGHT_H
#define KNiGHT_H
#include "radiant.h"

class Knight : public Radiant{
public:
    Knight(){
        name = "Knight";
        characteristics->setAll(50, 20, 15);
    };
    std::string getName() {return name;}
    Unit *itemCopy(){
        return new Knight(*this);
    }
};


#endif //KNiGHT_H
