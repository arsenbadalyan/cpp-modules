#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) {
    for (size_t i = 0; i < 4; i++) {
        this->_slots[i] = NULL;
    }
}

MateriaSource::MateriaSource( MateriaSource const & ref ) {
    *this = ref;
}

MateriaSource::~MateriaSource() {
    for (size_t i = 0; i < 4; i++) {
        delete this->_slots[i];
    }
}

MateriaSource& MateriaSource::operator=( MateriaSource const & rhs ) {
    if (this == &rhs)
        return (*this);

    for (size_t i = 0; i < 4; i++) {
        delete this->_slots[i];
        this->_slots[i] = rhs._slots[i]->clone();
    }
    
    return (*this);
}

void MateriaSource::learnMateria( AMateria * materia ) {
    for (size_t i = 0; i < 4; i++) {
        if (this->_slots[i] == materia)
            return ;
        if (!(this->_slots[i])) {
            this->_slots[i] = materia;
            return ;
        }
    }
    delete materia;
}

AMateria * MateriaSource::createMateria( std::string const & type ) {
    for (size_t i = 0; i < 4; i++) {
        if (this->_slots[i] && this->_slots[i]->getType() == type)
            return (this->_slots[i]->clone());
    }

    return (NULL);
}