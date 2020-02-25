//
// Created by kot on 25.02.2020.
//

#ifndef FIELD_H
#define FIELD_H

#include "libraries.h"

class Field;

class FieldItem{

public:
    virtual ~FieldItem() = default;
    virtual bool isMovable() = 0;
    virtual std::string about() = 0;
    virtual std::string shortName() = 0;
    virtual FieldItem* itemCopy() = 0;
    virtual void move(int x, int y) = 0;
};

class Field{
public:
    Field(unsigned width, unsigned height, unsigned itemLimit);
    Field(const Field &field);
    Field(Field &&field);

    bool addItem(unsigned x, unsigned y, FieldItem *item);
    bool deleteItem(unsigned x, unsigned y);
    bool deleteItem(FieldItem *item);
    FieldItem *getItem(unsigned x, unsigned y);
    Field &operator=(const Field &field);
    Field &operator=(Field &&field);

    ~Field();

private:
    unsigned width;
    unsigned height;
    unsigned itemLimit;
    unsigned itemCounter;
    FieldItem ***items;

};


class FieldIterator; // todo

class Unit: public FieldItem{
protected:
    unsigned healh;
    unsigned defence;
    unsigned damage;
};

class Melee{

};

class Range{

};

class Special{

};



/*
 * range  dryad(heal)   witch
 * melee  ork      golem
 * special dragon  griffin
 *
 * */



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

#endif //FIELD_H
