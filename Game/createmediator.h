//
// Created by kot on 20.05.2020.
//

#ifndef CREATEMEDIATOR_H
#define CREATEMEDIATOR_H
class Field;
class Base;
class Unit;

class CreateMediator {
private:
	Base* base;
	Field* field;
public:
	CreateMediator(Field* field, Base* base): field(field), base(base){}
	void notify(Unit* unit, unsigned x, unsigned y);
};


#endif //CREATEMEDIATOR_H
