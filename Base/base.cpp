#include "base.h"

Base::Base (int maxUnitsCount, int health,
			int xx, int yy, int baseNumb)
			: baseNumb(baseNumb), unitCount(0),
			maxCount(maxUnitsCount), unitCurr(0),
			health(health), x(xx), y(yy)
{
	units = new Composite;
	units->add(new Composite);
	units->add(new Composite);
	units->add(new Composite);
	for (auto i = 0; i < 3; i++)
	{
		units->getChildren(i)->add(new Leaf);
		units->getChildren(i)->add(new Leaf);
	}
}

std::string Base::shortName()
{
    return  "ⒷⒶⓈⒺ";
}

int Base::getBaseNumb () const {
	return baseNumb;
}

int Base::getX () const {
	return x;
}

int Base::getY () const {
	return y;
}

int Base::getUnitCount () const {
	return unitCount;
}

int Base::getMaxCount () const {
	return maxCount;
}

int Base::getHealth () const {
	return health;
}

Unit *Base::createUnit (UnitType type) {
	Unit* unit = nullptr;
	if (unitCount++ > maxCount)
	{
		std::cout << "max limit reached\n";
		return nullptr;
	}

	if (type == KNIGHT)
		unit = radiantFactory->createMelee();
	else if (type == DRAGON)
		unit = radiantFactory->createRange();
	else if (type == DRYAD)
		unit = radiantFactory->createSupport();
	else if (type == ORK)
		unit = direFactory->createMelee();
	else if (type == CHIMERA)
		unit = direFactory->createRange();
	else if (type == WITCH)
		unit = direFactory->createSupport();

	addUnit(unit);

	return unit;
}

void Base::addUnit (Unit *u) {
	auto unitName = u->getName();
	if (unitCount++ > maxCount)
	{
		std::cout << "max limit reached\n";
		throw std::range_error ("limit of units reached");
	}
	if (unitName == "Knight")
		units->getChildren(0)->getChildren(0)->addUnit(u);
	else if (unitName == "Dragon")
		units->getChildren(1)->getChildren(0)->addUnit(u);
	else if (unitName == "Dryad")
		units->getChildren(2)->getChildren(0)->addUnit(u);
	else if (unitName == "Orkk")
		units->getChildren(0)->getChildren(1)->addUnit(u);
	else if (unitName == "Chimera")
		units->getChildren(1)->getChildren(1)->addUnit(u);
	else if (unitName == "Witch")
		units->getChildren(2)->getChildren(1)->addUnit(u);
	unitCount++;


}

void Base::delUnit (Unit *u) {
	auto unitName = u->getName();
	if (unitName == "Knight")
		units->getChildren(0)->getChildren(0)->removeUnit(u);
	else if (unitName == "Dragon")
		units->getChildren(1)->getChildren(0)->removeUnit(u);
	else if (unitName == "Dryad")
		units->getChildren(2)->getChildren(0)->removeUnit(u);
	else if (unitName == "Orkk")
		units->getChildren(0)->getChildren(1)->removeUnit(u);
	else if (unitName == "Chimera")
		units->getChildren(1)->getChildren(1)->removeUnit(u);
	else if (unitName == "Witch")
		units->getChildren(2)->getChildren(1)->removeUnit(u);
	unitCount--;
	std::cout << "\nunit deleted\n";

}

//Unit *Base::getCurrUnit () {
//	return nullptr;
//}

bool Base::getDamage (int numb) {
	this->health -= numb;
	if (this->health <= 0){
		this->health = 0;
		return true;
	}
	return false;
}

std::string Base::printUnits ()
{
	return units->getUnits();
}

void Base::setCreateMediator (CreateMediator *value) {
	createMediator = value;
}

CreateMediator *Base::getCreateMediator () const {
	return createMediator;
}

void Base::setGameMediator (GameMediator *val) {
	gameMediator = val;
}

//void Base::delUnit (Subject *u) {
//
//}
