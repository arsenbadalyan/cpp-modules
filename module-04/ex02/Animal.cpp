#include "Animal.hpp"

Animal::Animal( void ) {
    std::cout << "Animal * CTOR * was called!" << std::endl;
    this->type = "animal";
}

Animal::Animal( const Animal& target ) {
    std::cout << "Animal * COPY CTOR * was called!" << std::endl;
    *this = Animal::operator=(target);
}

Animal::~Animal() {
    std::cout << "Animal * DTOR * was called!" << std::endl;
}

Animal& Animal::operator=(const Animal& rhs) {
    std::cout << "Animal * ASSIGNMENT OPERATOR * was called!" << std::endl;
    if (&rhs == this)
        return (*this);
    this->type = rhs.type;

    return (*this);
}

std::string Animal::getType( void ) const {
    return (this->type);
}

void Animal::setType( std::string newType ) {
    this->type = newType;
}