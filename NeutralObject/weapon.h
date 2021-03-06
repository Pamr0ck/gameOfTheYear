//
// Created by kot on 10.05.2020.
//

#ifndef WEAPON_H
#define WEAPON_H
#include "neutralObj.h"

class Weapon
{
public:
    virtual ~Weapon() = default;
    virtual void use(Unit&) = 0;
	virtual Neutraltype type()=0;
};

class GetWeapon : public NeutralObj
{
private:
    Weapon* weapon;
public:
    GetWeapon(Weapon* weapon) : weapon(weapon) {}

    ~GetWeapon()
    {
        delete weapon;
    }

    void operator += (Unit& unit)
    {
        weapon->use(unit);
    }

    std::string characteristics() const {return "weapon";}

    std::string getType() const {return "neutral";}
	Neutraltype getEnumType(){return  weapon->type();}
};



class Sting : public Weapon   // from Frodo with love
{
public:
	Neutraltype type() {return STING;}
    void use (Unit& unit)
    {
        unit.getCharacteristics()->setDamage(unit.getCharacteristics()->getDamage() + 30);
    }
};

class PurpleJediSword : public Weapon   // surprise mathe**cker
{
public:
	Neutraltype type() {return PURPLEJEDISWORD;}
    void use (Unit& unit)
    {
        unit.getCharacteristics()->setDamage(unit.getCharacteristics()->getDamage() + 70);
    }
};
class Excalibur : public Weapon
{
public:
	Neutraltype type() {return EXCALIBUR;}
	void use(Unit& unit)
	{
		unit.getCharacteristics()->setDamage(unit.getCharacteristics()->getDamage() + 100);
	}
};



#endif //WEAPON_H
