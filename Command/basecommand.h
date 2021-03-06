//
// Created by kot on 19.05.2020.
//

#ifndef BASECOMMAND_H
#define BASECOMMAND_H
#include "command.h"
#include "Base/base.h"

class BaseCommand : public Command
{
private:
	map<string, int> baseInfo();
	map<string, int> addUnit();
protected:
	map<string, int> noSuchAct();
	Base* base;
public:
	BaseCommand(Base* base, Actions action, map<string, Data> param);
	map<string, int> mainInfoAboutObj();
};


#endif //BASECOMMAND_H
