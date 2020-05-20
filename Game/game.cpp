//
// Created by kot on 20.05.2020.
//

#include "game.h"

Game::Game (unsigned int x, unsigned int y, unsigned int limit) {
	field = new Field(x, y, limit);
	units = new AttackMediator(field);
}

void Game::createBase (unsigned int maxUnits, int health, int x, int y, int baseNumb) {
	Base* base = new Base(maxUnits,health, x, y, baseNumb);
	gameMediator = new GameMediator(this, base);
	base->setGameMediator(gameMediator);
	bases.push_back(base);
}

void Game::createNeutral (Neutraltype obj, unsigned int x, unsigned int y) {
	NeutralObj* tmp = nullptr;
	switch (obj) {
		case STING:
			tmp = new GetWeapon(new Sting);
			break;
		case PURPLEJEDISWORD:
			tmp = new GetWeapon(new PurpleJediSword);
			break;
		case EXCALIBUR:
			tmp = new GetWeapon(new Excalibur);
			break;

		case HELMET:
			tmp = new GetArmor(new Helmet);
			break;
		case MITHRILHAUBERK:
			tmp = new GetArmor(new MithrilHauberk);
			break;
		case MANTLEOFINVISIBILITY:
			tmp = new GetArmor(new MantleOfInvisibility);
			break;
		case SWALLOW:
			tmp = new GetElixir(new Swallow);
			break;
		case THUNDERBOLT:
			tmp = new GetElixir(new Thunderbolt);
			break;
		case THEANCIENTDRINK:
			tmp = new GetElixir(new TheAncientDrink);
			break;
		case ANCIENTMOLD:
			tmp = new GetCurse(new AncientMold);
			break;
		case CHINESEGLASSES:
			tmp = new GetCurse(new ChineseGlasses);
			break;
		case COVID:
			tmp = new GetCurse(new Covid);
			break;
	}
	field->addNeutral(tmp,x,y);
}

void Game::addUnit (Unit *unit, Base *base) {
	for(auto *b :bases)
		if (b == base)
		{
			units->addUnit(unit);
			b->addUnit(unit);
			// to base?
			return;
		}
	throw invalid_argument("Error! No such base in the game!!!");
}

void Game::deleteUnit (Unit *unit, Base *base) {
	for(auto *b :bases)
		if (b == base)
		{
			units->deleteUnit(unit);
			b->delUnit(unit);
			// to base?
			return;
		}
	throw invalid_argument("Error! No such base in the game!!!");
}

Base *Game::getBaseByNum (int num) {
	for(auto *b :bases)
		if (b->getBaseNumb() == num)
			return b;
	throw invalid_argument("Error! No such base in the game!!!");
}

std::vector<Base *> Game::getBases () const {
	return bases;
}

std::vector<Unit *> Game::getUnits () const {
	return units->getUnits();
}

Field *Game::getField () const {
	return field;
}
