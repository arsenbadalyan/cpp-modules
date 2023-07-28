#include "Weapon.hpp"

Weapon::Weapon( void ) {
	this->m_type = "";
}

Weapon::Weapon(std::string type) {
	this->m_type = type;
}

Weapon::~Weapon() {}

const std::string& Weapon::getType( void ) const {
	return (this->m_type);
}

void Weapon::setType( std::string type ) {
	this->m_type = type;
}