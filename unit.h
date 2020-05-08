//
// Created by kot on 25.02.2020.
//

#ifndef UNIT_H
#define UNIT_H

#include "field.h"
#include "characteristics.h"
#include "moveMediator.h"
#include "subject.h"

//class IObserver : public FieldItem
//{
//public:
////    virtual void deleteUnit(FieldItem* obj) = 0;
//};

class Unit : public Subject
{
public:
    Unit(){}
    Unit(Unit&);
    virtual ~Unit();

    virtual bool isMovable();

    virtual std::string getName() = 0;
    virtual std::string about();

    virtual Unit* itemCopy() = 0;

    virtual void setMoveMediator(MoveMediator*);

    virtual void move(int, int);

    std::string getType() const;

    void setHealth(int);
    void setDamage(int);
    void setArmor(int);


protected:
    std::string name;
    bool movable = true;
    Characteristics* characteristics;
    MoveMediator* moveMediator;
};

class UnitFactory {
public:
    virtual Radiant *createRadiant() = 0;
    virtual Dire *createDire() = 0;
};

class MeleeFactory : public UnitFactory {
public:
    Radiant * createRadiant(){
        return new Knight();
    }
    Dire * createDire(){
        return new Ork();
    }
};

class SupportFactory : public UnitFactory {
public:
    Radiant * createRadiant(){
        return new Dryad();
    }
    Dire * createDire(){
        return new Witch();
    }
};

class RangeFactory : public UnitFactory {
public:
    Radiant * createRadiant(){
        return new Dragon();
    }
    Dire * createDire(){
        return new Chimera();
    }
};


#endif //UNIT_H
