//
// Created by kot on 20.05.2020.
//

#ifndef GAMEMEDIATOR_H
#define GAMEMEDIATOR_H

class Game;
class Unit;
class  Base;


class GameMediator
{
public:
	GameMediator(Game* game, Base* base);
	void notify(Unit* u, bool add);
	~GameMediator() = default;

private:
	Game* game;
	Base* base;
};


#endif //GAMEMEDIATOR_H
