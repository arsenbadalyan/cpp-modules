#include "AMateria.hpp"

AMateria::AMateria( std::string const & type ) : _type(type) { }

std::string const & AMateria::getType( void ) const {
    return (this->_type);
}