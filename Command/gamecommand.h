//
// Created by kot on 20.05.2020.
//

#ifndef GAMECOMMAND_H
#define GAMECOMMAND_H
#include "command.h"
#include "Game/game.h"
#include "basecommand.h"
#include "fieldcommand.h"
#include "Game/createmediator.h"
class GameCommand : public Command{
private:
	map<string, int> baseInfo();
	map<string, int> gameInfo();
	map<string, int> attack();
	map<string, int> move();
	map<string, int> addBase();
	map<string, int> addNeutral();
	map<string, int> addUnit();
protected:
	Game* game;
	map<string, int> noSuchAct();
public:
	GameCommand(Game* game, Actions act, map<string, Data> param);
	map<string, int> mainInfoAboutObj();
};

#endif //GAMECOMMAND_H
