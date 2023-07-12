#include "HumanB.hpp"

HumanB::HumanB(std::string name, Weapon& weapon) {
	this->m_name = name;
	this->m_weapon = &weapon;
}

HumanB::HumanB(std::string name) {
	this->m_name = name;
	this->m_weapon = NULL;
}

HumanB::~HumanB() {}

void HumanB::setWeapon( Weapon& weapon ) {
	this->m_weapon = &weapon;
}

void HumanB::attack( void ) {
	if (this->m_weapon == NULL)
		std::cout << this->m_name << " cannot attack without weapon !!" << std::endl;
	else
		std::cout << this->m_name << " attacks with their " << this->m_weapon->getType() << std::endl;
}
