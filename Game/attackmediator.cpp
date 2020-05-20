//
// Created by kot on 20.05.2020.
//

#include "attackmediator.h"
#include "unit.h"
#include "field.h"

AttackMediator::AttackMediator (Field *field): field(field) {}

void AttackMediator::addUnit (Unit *u) {
	units.push_back(u);
	u->setAttackMediator(this);
}

void AttackMediator::deleteUnit (Unit *u) {
	for (auto iter = units.begin(); iter!= units.end(); iter++)
		if(*iter == u){
			units.erase(iter);
			return;
		}
}

void AttackMediator::attack (Unit *attaker, int x, int y) {
	bool attakerExists;
	unsigned reciverX;
	unsigned reciverY;
	for (auto i = 0; i< field->getWidth(); i++)
		for (auto j = 0; j< field->getHeight(); j++)
			if (field->getItem(i,j)->getUnit() == attaker)
			{
				attakerExists = true;
				reciverX = i;
				reciverY = j;
			}
	if(!attakerExists){
		throw std::invalid_argument("there is not such attack unit");
	}
	auto* reciver = field->getItem(reciverX+x, reciverY + y)->getUnit();
	if(!reciver)
		throw invalid_argument("there is no unit on position" + to_string(reciverX+x) + to_string(reciverY+y));

	for (auto u:units)
	{
		if (u == reciver)
		{
			if(u->getBaseNumber() == attaker->getBaseNumber())
				throw invalid_argument("they are friends");
			if(!u->recieveAttack(attaker))
				field->deleteUnit(reciverX+x, reciverY + y);
		}
		return;

	}
}

std::vector<Unit *> AttackMediator::getUnits () const {
	return units;
}
