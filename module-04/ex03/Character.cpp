#include "Character.hpp"

Character::Character( std::string const & name ) : _name(name) {
    for (size_t i = 0; i < 4; i++) {
        this->_slots[i] = NULL;
    }
}

Character::Character( Character const & ref ) {
    *this = ref;
}

Character::~Character() { }

Character& Character::operator=( Character const & rhs ) {
    if (this == &rhs)
        return (*this);

    this->_name = rhs._name;
    for (size_t i = 0; i < 4; i++)
        this->_slots[i] = rhs._slots[i];
    
    return (*this);
}

std::string const & Character::getName( void ) const {
    return (this->_name);
}

void Character::equip( AMateria* target ) {
    for (size_t i = 0; i < 4; i++) {
        if (!this->_slots[i])
            this->_slots[i] = target;
    }
}

void Character::unequip( int idx ) {
    if (idx >= 0 && idx < 4)
        this->_slots[idx] = NULL;
}

void Character::use( int idx, ICharacter const & target ) {
    if (idx >= 0 && idx < 4)
        this->_slots[idx]->use(target);
}