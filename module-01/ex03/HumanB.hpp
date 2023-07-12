#ifndef __HUMANB__H__
#define __HUMANB__H__

#include <iostream>
#include "Weapon.hpp"

class HumanB {

public:

	HumanB(std::string, Weapon&);
	HumanB(std::string);
	~HumanB();
	void attack(void);
	void setWeapon(Weapon&);

private:
	
	std::string m_name;
	Weapon* m_weapon;

};

#endif  //!__HUMANB__H__