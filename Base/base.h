#ifndef BASE_H
#define BASE_H

#include "composite.h"
#include "../Units/Factory/direFactory.h"
#include "../Units/Factory/radiantFactory.h"
#include "enums.h"

class Base
{
public:
    Base(int, int, int, int, int);

    int getBaseNumb() const;
    int getX() const;
    int getY()const;
    int getUnitCount() const;
    int getMaxCount() const;
    int getHealth() const;
    Unit *createUnit (UnitType type);
    void addUnit(Unit* u);
    void delUnit(Unit* u);
//	void delUnit(Subject* u);
//    Unit* getCurrUnit();
    bool getDamage(int);
    std::string printUnits();

    std::string shortName();
private:
    std::string name;
    int baseNumb;
    int unitCount;
    const int maxCount;
    int health;
    const int x, y;
    int unitCurr;
    Component* units;
    UnitFactory* direFactory = new DireFactory();
    UnitFactory* radiantFactory = new RadiantFactory();

};

#endif // BASE_H
