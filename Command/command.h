//
// Created by kot on 19.05.2020.
//
#include <map>
#include <iostream>
#include "enums.h"
#ifndef COMMAND_H
#define COMMAND_H
using namespace std;
struct Data
{
	int x, y;
	UnitType unitType;
	Neutraltype neutraltype;
	int base;
};
class Command
{
public:
	virtual  map <string, int> mainInfoAboutObj() = 0;
	virtual ~Command() = default;
protected:
	virtual  map <string, int> noSuchAct() = 0;
	Actions action;
	map <string, Data> params;
};
#endif //COMMAND_H
