//
// Created by kot on 20.05.2020.
//

#ifndef GAME_H
#define GAME_H
#include "field.h"
#include "gamemediator.h"
#include "weapon.h"
#include "armor.h"
#include "elixir.h"
#include "curse.h"

class Game
{
public:
	Game(unsigned x, unsigned y, unsigned limit);
	void createBase( unsigned  maxUnits, int health, int x, int y, int baseNumb);
	void createNeutral(Neutraltype obj,unsigned x, unsigned y);
	void addUnit(Unit *unit, Base *base);
	void deleteUnit(Unit *unit, Base *base);
	Base* getBaseByNum(int num);

	std::vector<Base *> getBases() const;

	std::vector<Unit *> getUnits() const;
	Field *getField() const;

private:
	Field* field;
	vector<Base*> bases;
	AttackMediator* units;
	GameMediator* gameMediator;
};


#endif //GAME_H
