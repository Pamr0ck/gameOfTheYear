//
// Created by kot on 20.05.2020.
//

#include "gamecommand.h"

map<string, int> GameCommand::baseInfo () {
	map<string, int> info;
	auto baseNum = params.find("base num")->second.x;
	if (baseNum >= 0)
	{
		if (baseNum < game->getBases().size())
		{
			BaseCommand com(game->getBaseByNum(baseNum), action, params);
			return  com.mainInfoAboutObj();
		} else
			info["there is no base with this number "] = baseNum;

	} else
		info["base number mast be >= "] = 0;
	return info;
}

map<string, int> GameCommand::gameInfo () {
	map<string, int> info;
	info["field height "] = game->getField()->getHeight();
	info["field width "] = game->getField()->getWidth();
	info["field max items "] = game->getField()->getMaxItems();
	info["items count on field "] = game->getField()->getItemCounter();
	info["base count "] = game->getBases().size();
	return  info;
}

map<string, int> GameCommand::attack () {
	map<string, int> info;
	FieldCommand com(game->getField(), action, params);
	auto * u = com.returnUnit();
	if (!u)
	{
		info["no soch unit"] = 0;
		return  info;
	}
	try {
		for (auto* iter : game->getUnits())
		{
			iter->attack(params.find("attack pos")->second.x,
			             params.find("attack pos")->second.y);
			info["attack was "] = 0;
			return info;
		}
	}
	catch (invalid_argument& e) {
		info[e.what()] = 0;
		return  info;
	}
	info["no such attacker"] = -1;
	return info;
}

map<string, int> GameCommand::move () {
	FieldCommand com(game->getField(), action, params);
	return com.mainInfoAboutObj();
}

map<string, int> GameCommand::addBase () {
	map<string, int> info;
	auto maxUnit = params.find("addParams")->second.x;
	auto health = params.find("addParams")->second.y;
	auto x = params.find("pos")->second.x;
	auto y = params.find("pos")->second.y;
	auto baseNumb = params.find("addParams")->second.base;
	try{
		if(game->getField()->getItem(x,y)->getBase())
			throw invalid_argument ("there is a base on cell");
		else{
			game->createBase(maxUnit, health, x, y, baseNumb);
			info["base was created "]= baseNumb;
		}
	}
	catch (out_of_range& e){
		info[e.what()] = 0;
	}
	return info;

}

map<string, int> GameCommand::addNeutral () {
	map<string, int> info;
	auto x = params.find("addParams")->second.x;
	auto y = params.find("addParams")->second.y;
	try {
		game->createNeutral(params.find("addParams")
		->second.neutraltype,x,y);
		info["neutral added"] = ADD_NEUTRAL;
		info["pos x "] = x;
		info["pos y "] = y;
	}
	catch(out_of_range& e){
		info[e.what()]=0;
	}catch(invalid_argument& e){
		info[e.what()]=0;
	}
	return info;
}

map<string, int> GameCommand::addUnit () {
	auto baseNum = params.find("addParasm")->second.base;
	Base* base;
	try {
		base = game->getBaseByNum(baseNum);
	}
	catch (invalid_argument& e) {
		map<string, int> info;
		info[e.what()]=0;
		return info;
	}
	CreateMediator* createMediator = new CreateMediator(game->getField(),base);
	base->setCreateMediator(createMediator);
	game->getField()->setCreateMediator(createMediator);
	BaseCommand com(base, action, params);
	return  com.mainInfoAboutObj();
}

map<string, int> GameCommand::noSuchAct () {
	map<string, int> info;
	info["no such action"] = 0;
	return  info;
}

GameCommand::GameCommand (Game *game, Actions act, map<string, Data> param) {
	this->game = game;
	action = act;
	params = param;
}

map<string, int> GameCommand::mainInfoAboutObj () {
	switch (action) {
		case GAME_INFO:
			return  gameInfo();
		case BASE_INFO:
			return  baseInfo();
		case MAP_LAND:
		case MAP_UNITS:
		case UNIT_INFO:
		{
			FieldCommand com(game->getField(), action, params);
			return  com.mainInfoAboutObj();
		}
		case ATTACK:
			return attack();
		case MOVE:
			return move();
		case ADD_BASE:
			return  addBase();
		case ADD_NEUTRAL:
			return addNeutral();
		case ADD_UNIT:
			return  addUnit();
		default:
			return noSuchAct();
	}
}
