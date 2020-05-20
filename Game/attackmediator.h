//
// Created by kot on 20.05.2020.
//

#ifndef ATTACKMEDIATOR_H
#define ATTACKMEDIATOR_H
#include <vector>
using namespace std;
class Unit;
class Field;

class AttackMediator
{
public:
	AttackMediator(Field* field);
	void addUnit(Unit* u);
	void deleteUnit(Unit* u);
	void attack(Unit* attaker, int x, int y);
	std::vector<Unit *> getUnits() const;
private:
	std::vector<Unit*> units;
	Field* field;
};


#endif //ATTACKMEDIATOR_H
