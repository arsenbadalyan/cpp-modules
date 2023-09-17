#include "Cure.hpp"

Cure::Cure( void ) : AMateria::AMateria( "cure" ) {}

Cure::Cure( Cure const & target ) : AMateria::AMateria(target) {
    Cure::operator=(target);
}

Cure::~Cure() {}

Cure& Cure::operator=( Cure const & rhs ) {
    if (this != &rhs)
        this->_type = rhs._type;
    return (*this);
}

AMateria* Cure::clone( void ) const {
    return ((AMateria *)(new Cure(*this)));
}

void Cure::use( ICharacter const & target ) {
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}