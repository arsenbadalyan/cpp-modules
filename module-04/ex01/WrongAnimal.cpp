#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) {
    std::cout << "WrongAnimal * CTOR * was called!" << std::endl;
    this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal( const WrongAnimal& target ) {
    std::cout << "WrongAnimal * COPY CTOR * was called!" << std::endl;
    if (&target == this)
        return;
    this->type = target.type;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal * DTOR * was called!" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs) {
    std::cout << "WrongAnimal * ASSIGNMENT OPERATOR * was called!" << std::endl;
    if (&rhs == this)
        return (*this);
    this->type = rhs.type;

    return (*this);
}

void WrongAnimal::makeSound( void ) const {
    std::cout << "WrongAnimal class don't have any soundd!!" << std::endl;
}

std::string WrongAnimal::getType( void ) const {
    return (this->type);
}

void WrongAnimal::setType( std::string newType ) {
    this->type = newType;
}