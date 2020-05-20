//
// Created by kot on 19.05.2020.
//

#include "fieldcommand.h"

//map<string, int> FieldCommand::landInfo () {
//	return map<string, int>();
//}

map<string, int> FieldCommand::unitInfo () {
	map<string, int> info;
	auto x = params.find("infoParams")->second.x;
	auto y = params.find("infoParams")->second.y;
	Unit* u = field->getItem(x, y)->getUnit();
	if (u)
		info["unit characteristics:\n" + u->about()]=0;
	return info;
}

map<string, int> FieldCommand::getUnitMap () {
	map<string, int> info;
	info[field->getUnitMap()]=0;
	return info;
}

map<string, int> FieldCommand::getLandMap () {
	map<string, int> info;
	info[field->getLandMap()]=0;
	return info;
}

map<string, int> FieldCommand::moveUnit () {
	map<string, int> info;
	Unit* u = returnUnit();
	try
	{
		u->move(params.find("move")->second.x,
		        params.find("move")->second.y);
		info["move unit"] = u->getEnumType();
	}
	catch(out_of_range& e){info[e.what()]=0;}
	catch(invalid_argument& e){info[e.what()]=0;}
	return info;
}

//map<string, int> FieldCommand::findUnit () {
//	map<string, int> info;
//	if(!unit)
//	{
//		info["unit can't be null"] = 0;
//		return info;
//	}
////	for (FieldIterator i(field); i.isActive(); ++i)
//	for(auto i = 0; i < field->getWidth(); ++i)
//		for(auto j = 0; j < field->getWidth(); ++j)
//		if(field->getItem(i,j)->getUnit() == unit)
//		{
//			info["pos x"] = i;
//			info["pos y"] = j;
//		}
//	if(info.empty())
//		info["no such unit el"] = -1;
//	return  info;
//}

//map<string, int> FieldCommand::findneutral () {
//	return map<string, int>();
//}

map<string, int> FieldCommand::noSuchAct () {
	map<string, int> info;
	info["no such action"] = 0;
	return info;
}

FieldCommand::FieldCommand (Field *field, Actions action,
							map<string, Data> param) {
	this->field = field;
	this->action = action;
	params = param;
	unit = nullptr;
	neutral = nullptr;
}

FieldCommand::FieldCommand (Field *field, Actions action,
		map<string, Data> param, Unit *unit, NeutralObj *neutral) {
	this->field = field;
	this->action = action;
	params = param;
	this->unit = unit;
	this->neutral = neutral;
}

Unit *FieldCommand::returnUnit () {
	auto x = params.find("pos")->second.x;
	auto y = params.find("pos")->second.y;
	return  field->getItem(x,y)->getUnit();
}

map<string, int> FieldCommand::mainInfoAboutObj () {
	return map<string, int>();
}
