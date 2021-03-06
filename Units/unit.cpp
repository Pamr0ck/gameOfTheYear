//
// Created by kot on 25.02.2020.
//

#include "unit.h"

Unit::Unit(Unit &unit):
        name(unit.name), movable(unit.movable),
        characteristics(unit.characteristics), moveMediator(nullptr){}

Unit::~Unit()
{
    delete moveMediator;
}

bool Unit::isMovable () {
    return movable;
}

std::string Unit::about()
{
    std::string output;
    output += getName();
    output += "\nCharacteristics:";
    output += "\nHealth: " + std::to_string(characteristics->getHealth()) +
              "\nDamage: " + std::to_string(characteristics->getDamage()) +
              "\nArmor: " + std::to_string(characteristics->getArmor());
    return output+"\n";
}

void Unit::setMoveMediator(MoveMediator *value)
{
    moveMediator = value;
}

void Unit::move(int x, int y)
{
    moveMediator->movObj(this, x, y);
}

std::string Unit::getType () const
{
    return "unit";
}

Characteristics *Unit::getCharacteristics () const {
    return characteristics;
}


void Unit::setHealth (int val)
{
    characteristics->setHealth(val);
}

void Unit::setDamage (int val)
{
    characteristics->setDamage(val);
}

void Unit::setArmor (int val)
{
    characteristics->setArmor(val);
}

void Unit::setAttackMediator (AttackMediator *value) {
	attackMediator = value;
}

void Unit::attack (int x, int y) {
	attackMediator->attack(this, x, y);
}

bool Unit::recieveAttack (Unit *u) {
	auto * attacker = u->getCharacteristics();
	auto armor = characteristics->getArmor() - attacker->getDamage();
	if (armor < 0)
	{
		characteristics->setArmor(0);
		auto health = characteristics->getHealth() + armor ; //armor < 0 => -armor
		if(health <= 0)
			return  false;
		else
			characteristics->setHealth(health);
	}
	else
		characteristics->setArmor(armor);
	return true;
}

int Unit::getBaseNumber () const {
	return baseNumber;
}
