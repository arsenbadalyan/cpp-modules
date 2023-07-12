#ifndef __HUMANA__H__
#define __HUMANA__H__

#include <iostream>
#include "Weapon.hpp"

class HumanA {

public:

	HumanA(std::string, Weapon&);
	~HumanA();
	void attack(void);

private:
	
	std::string m_name;
	Weapon* m_weapon;

};

#endif  //!__HUMANA__H__