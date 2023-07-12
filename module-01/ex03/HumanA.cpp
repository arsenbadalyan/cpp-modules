#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) {
	this->m_name = name;
	this->m_weapon = &weapon;
}

HumanA::~HumanA() {}

void HumanA::attack( void ) {
	std::cout << this->m_name << " attacks with their " << this->m_weapon->getType() << std::endl;
}