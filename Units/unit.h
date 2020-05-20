//
// Created by kot on 25.02.2020.
//

#ifndef UNIT_H
#define UNIT_H
#include <iostream>
#include "characteristics.h"
#include "moveMediator.h"
#include "subject.h"
#include "enums.h"
#include "Game/attackmediator.h"


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
    virtual UnitType getEnumType() const = 0;

    virtual Characteristics* getCharacteristics()const;

    void setHealth(int);
    void setDamage(int);
    void setArmor(int);

	void setAttackMediator(AttackMediator *value);
	void attack(int x, int y);

	bool recieveAttack(Unit* u);
	int getBaseNumber() const;


protected:
    std::string name;
    bool movable = true;
    Characteristics* characteristics;
    MoveMediator* moveMediator;
	AttackMediator* attackMediator;
	int baseNumber;
};
#endif //UNIT_H
