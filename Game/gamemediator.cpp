//
// Created by kot on 20.05.2020.
//
#include "gamemediator.h"
#include "game.h"
#include "Base/base.h"

GameMediator::GameMediator (Game *game, Base *base):game(game), base(base) {
	base->setGameMediator(this);

}
