#include "AMateria.hpp"

AMateria::AMateria( void ) {}

AMateria::AMateria( std::string const & type ) : _type(type) { }

AMateria::AMateria( AMateria const & target ) {
    *this = target;
}

AMateria::~AMateria() {}

std::string const & AMateria::getType( void ) const {
    return (this->_type);
}

void AMateria::use( ICharacter const & target ) {
    std::cout << "Pure * use * method called for " << target.getName() << std::endl;
}