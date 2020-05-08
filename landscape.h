#ifndef LANDSCAPE_H
#define LANDSCAPE_H

#include <iostream>

class Landscape
{
public:
    virtual std::string getType() const = 0;
    virtual bool canMove() = 0;
    virtual bool canAttack() = 0;
};

class River : public Landscape
{
protected:
    std::string type = "R";
public:
    std::string getType() const;
//    Landscape * itemCopy(){
//        return new River(*this);
//    }
};

class Forest : public Landscape
{
protected:
    std::string type = "F";
public:
    std::string getType() const;
//    Landscape * itemCopy(){
//        return new Forest(*this);
//    }
};


class Desert : public Landscape
{
protected:
    std::string type = "D";
public:
    std::string getType() const;
//    Landscape * itemCopy(){
//        return new Desert(*this);
//    }
};


class Proxy : public Landscape
{
private:
    Landscape* landscape;

public:
    Proxy(std::string type);
    bool checkMoveAccess(std::string unitType) const;
    bool checkAttackAccess(std::string unitType) const;
    std::string getType() const;
};



#endif // LANDSCAPE_H
