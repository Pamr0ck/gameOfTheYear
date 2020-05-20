#ifndef LANDSCAPE_H
#define LANDSCAPE_H

#include <iostream>
#include "enums.h"
class Landscape
{
public:
    virtual std::string getType() const = 0;
//    virtual bool canMove() = 0;
//    virtual bool canAttack() = 0;
    virtual ~Landscape() = default;
    virtual  LandType getEnumType() const = 0;
};

class River : public Landscape
{
protected:
    std::string type = "River";
public:
    std::string getType() const {return  type;};
	LandType getEnumType() const {return RIVER;}
};

class Forest : public Landscape
{
protected:
    std::string type = "Forest";
public:
    std::string getType() const {return  type;};
	LandType getEnumType() const {return FOREST;}
};


class Desert : public Landscape
{
protected:
    std::string type = "Desert";
public:
    std::string getType() const {return  type;};
	LandType getEnumType() const {return DESERT;}
};

#endif // LANDSCAPE_H
