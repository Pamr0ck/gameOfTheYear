//
// Created by kot on 25.02.2020.
//

#ifndef UNIT_H
#define UNIT_H

#include "field.h"


class Unit : public FieldItem
{
public:
    Unit() {}
    Unit(Unit &unit);

//    virtual ~Unit() {
//        //p 6
//    }
    virtual  ~Unit() = default;

    virtual bool isMovable() {
        return movable;
    }

    virtual std::string shortName() = 0;
    virtual std::string about();
    virtual FieldItem *itemCopy() = 0;

//    virtual Skills getAttackSkills() const;
//    virtual Skills getSecuritySkills() const;
//    virtual Skills getCharacteristics() const;

//    virtual void setAttackBonus(int bonus);
//    virtual void setSecurityBonus(int bonus);
//    virtual void setCharacteristicsBonus(int bonus);

//    virtual void setMoveMediator(MoveMediator *value);

    virtual void move(int x, int y);

protected:
    std::string name;
    bool movable = true;
    unsigned healh;
    unsigned defence;
    unsigned attack;
//    Skills attackSkills;
//    Skills securitySkills;
//    Skills characteristics;
//    MoveMediator *moveMediator = nullptr;
};


#endif //UNIT_H
