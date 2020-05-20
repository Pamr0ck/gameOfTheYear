//
// Created by kot on 25.02.2020.
//

#ifndef FIELD_H
#define FIELD_H

#include "fieldItem.h"
#include "proxy.h"
#include "base.h"

using namespace std;

class Field : Observer{
public:
    Field(unsigned width, unsigned height, unsigned maxItems);
    Field(const Field &field);
    Field(Field &&field);
	Field &operator=(const Field &field);
	Field &operator=(Field &&field);

	unsigned getWidth() const;
    unsigned getHeight() const;

	bool moveUnit(Unit*, int, int);

	void setMoveMediator(MoveMediator *value);

	unsigned getMaxItems() const;
	bool isCellFreeForUnit(size_t, size_t);


	bool addUnit (Unit *item, unsigned x, unsigned y, int baseNum = 1);
	bool deleteUnit(unsigned x, unsigned y);

//	bool deleteItem(FieldItem *item);

//	Base* getBase()const;

	bool addNeutral(NeutralObj*, unsigned, unsigned);
	bool deleteNeutral(unsigned, unsigned);

	std::string getAbout(unsigned x, unsigned y);
//	FieldItem* getCell(unsigned x, unsigned y);
	FieldItem* findUnit(Unit *unit);
	void update(Subject *);
	void deleteUnit(Subject*);
//	void setBase(Base*);
	string printBase(Base *base);

	string getUnitMap();
	string getLandMap();
	FieldItem *getItem(unsigned x, unsigned y) const;
	unsigned getItemCounter() const;
	//string getNeutralMap();


//	std::string getShortInfo();



//    void addLand(unsigned x, unsigned y, Proxy *landscape);

    ~Field();

private:
    const unsigned width;
    const unsigned height;
    const unsigned maxItems;
    unsigned itemCounter;
    FieldItem ***items;
    MoveMediator *moveMediator = nullptr;

//    Base* base;
};


class FieldIterator
{
public:
    FieldIterator(const Field *field);
    bool isActive() const;
    FieldItem *operator->() const;
    FieldItem *operator++();

private:
    bool active;
    const Field *field;
    unsigned curWidth;
    unsigned curHeight;
};


#endif //FIELD_H
