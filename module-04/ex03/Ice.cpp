#include "Ice.hpp"

Ice::Ice( void ) : AMateria::AMateria( "ice" ) {}

Ice::Ice( Ice const & target ) : AMateria::AMateria(target._type) { }

Ice& Ice::operator=( Ice const & rhs ) {
    if (this != &rhs)
        this->_type = rhs._type;

    return (*this);
}

Ice::~Ice() { }

AMateria* Ice::clone( void ) const {
    return ((AMateria *)(new Ice(*this)));
}

void Ice::use( ICharacter const & target ) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}