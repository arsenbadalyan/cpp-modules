#include "Character.hpp"

Character::Character( std::string const & name ) : _name(name) {
    _floor_slots = NULL;
    for (size_t i = 0; i < 4; i++) {
        this->_slots[i] = NULL;
    }
}

Character::Character( Character const & ref ) {
    *this = ref;
}

Character::~Character() {

    size_t i = 0;

    while (_floor_slots && _floor_slots[i]) {
        bool hasInSlots = false;
        for (size_t j = 0; j < 4; j++) {
            if (_floor_slots[i] == this->_slots[j]) {
                hasInSlots = true;
            }
        }
        if (!hasInSlots)
            delete _floor_slots[i];
        i++;
    }

    for (size_t i = 0; i < 4; i++) {
        delete this->_slots[i];
    }

}

Character& Character::operator=( Character const & rhs ) {
    if (this == &rhs)
        return (*this);

    this->_name = rhs._name;
    for (size_t i = 0; i < 4; i++) {
        delete this->_slots[i];
        this->_slots[i] = rhs._slots[i]->clone();
    }
    
    return (*this);
}

std::string const & Character::getName( void ) const {
    return (this->_name);
}

void Character::equip( AMateria* target ) {
    if (!target)
        return ;

    for (size_t i = 0; i < 4; i++) {
        if (this->_slots[i] == target)
            return ;
    }

    for (size_t i = 0; i < 4; i++) {
        if (!(this->_slots[i])) {
            this->_slots[i] = target;
            return ;
        }
    }

    save_materia(target);
}

void Character::unequip( int idx ) {
    if (idx >= 0 && idx < 4 && this->_slots[idx]) {
        save_materia(this->_slots[idx]);
        this->_slots[idx] = NULL;
    }
}

void Character::use( int idx, ICharacter & target ) {
    if (idx >= 0 && idx < 4)
        this->_slots[idx]->use(target);
}

void Character::save_materia( AMateria * materia ) {
    size_t slotSize = 2;
    size_t idx = 0;
    AMateria **cp = _floor_slots;

    if (_floor_slots) {
        while (_floor_slots[idx++])
            slotSize++;
    }

    _floor_slots = new AMateria*[slotSize];
    _floor_slots[slotSize - 1] = NULL;
    
    idx = 0;
    while (cp && cp[idx]) {
        _floor_slots[idx] = cp[idx];
        idx++;
    }

    _floor_slots[idx] = materia;
}
