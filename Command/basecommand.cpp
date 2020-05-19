//
// Created by kot on 19.05.2020.
//

#include "basecommand.h"

map<string, int> BaseCommand::baseInfo () {
	map<string, int> info;
	info["base number"] = base->getBaseNumb();
	info["coord x"] = base->getX();
	info["coord y"] = base->getY();
	info["unit count in base"] = base->getUnitCount();
	info["max unit in base"] = base->getMaxCount();
	info["base health"] = base->getHealth();
	// TODO вывод всех юнитов
	return info;
}

map<string, int> BaseCommand::addUnit () {
	map<string, int> info;
	Data data = params.find("addParams")->second;   //what?
	try {
		Unit* u = base->createUnit(data.unitType);
		info["unit added. name: "+ u->getName()] = 1;
	}
	catch (out_of_range& e) {info[e.what()] = 0;}
	catch (invalid_argument& e) {info[e.what()] = 0;}
	return info;
}

map<string, int> BaseCommand::noSuchAct () {
	 map<string, int> info;
	 info["no such action"] = 0;
	 return  info;
}

BaseCommand::BaseCommand (Base *base, Actions action, map<string, Data> param)
{
	this->base = base;
	this->action = action;
	this->params = param;
}

map<string, int> BaseCommand::mainInfoAboutObj () {
	return (action == BASE_INFO ? baseInfo() : (action == ADD_UNIT) ? addUnit() :noSuchAct());
}
