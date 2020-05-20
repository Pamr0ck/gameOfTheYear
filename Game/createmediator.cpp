//
// Created by kot on 20.05.2020.
//

#include "createmediator.h"
#include "field.h"

void CreateMediator::notify (Unit *unit, unsigned int x, unsigned int y)
{
		field->addUnit(unit, x, y);
}
