//
// Created by kot on 19.05.2020.
//

#ifndef FIELDCOMMAND_H
#define FIELDCOMMAND_H
#include "command.h"
#include "Field/field.h"


class FieldCommand: public Command {
private:
//	map<string, int> landInfo();
	map<string, int> unitInfo();
	map<string, int> getUnitMap();
	map<string, int> getLandMap();
	map<string, int> moveUnit();
//	map<string, int> findUnit();
//	map<string, int> findneutral();

protected:
	map<string, int> noSuchAct();
	Field* field;
	Unit* unit;
	NeutralObj* neutral;
public:
	FieldCommand(Field* field, Actions action, map<string, Data> param);
	FieldCommand(Field* field, Actions action, map<string, Data> param, Unit* unit, NeutralObj* neutral);
	Unit* returnUnit();
	map<string, int> mainInfoAboutObj();
};


#endif //FIELDCOMMAND_H
