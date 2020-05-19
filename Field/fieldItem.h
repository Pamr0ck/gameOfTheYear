#ifndef FIELDITEM_H
#define FIELDITEM_H

#include "../NeutralObject/neutralObj.h"
#include "../Landscape/landscape.h"

class FieldItem
{
public:
    FieldItem();
    FieldItem(const FieldItem&);
    FieldItem(FieldItem&&);
    ~FieldItem();
    FieldItem& operator = (const FieldItem&);
    FieldItem& operator = (FieldItem&&);
    void addUnit(Unit*);
    void delUnit();
    void addNeutral(NeutralObj*);
    void delNeutral();
    void setLandscape(Landscape*);
    void delLandscape();
    bool isUnitFree() const;
    Unit* getUnit() const;
    NeutralObj* getNeutral() const;
    Landscape* getLandscape() const;

private:
    Unit* unit;
    NeutralObj* neutral;
    Landscape* land;
};

#endif //FIELDITEM_H
