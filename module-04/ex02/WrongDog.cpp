#include "WrongDog.hpp"

WrongDog::WrongDog( void ) : WrongAnimal::WrongAnimal() {
    std::cout << "WrongDog * CTOR * was called!" << std::endl;
    this->type = "WrongDog";
}

WrongDog::WrongDog( const WrongDog& target ) : WrongAnimal::WrongAnimal(target) {
    std::cout << "WrongDog * COPY CTOR * was called!" << std::endl;
}

WrongDog::~WrongDog() {
    std::cout << "WrongDog * DTOR * was called!" << std::endl;
}

WrongDog& WrongDog::operator=(const WrongDog& rhs) {
    WrongAnimal::operator=(rhs);
    std::cout << "WrongDog * ASSIGNMENT OPERATOR * was called!" << std::endl;

    return (*this);
}

void WrongDog::makeSound( void ) const {
    std::cout << "Bark!!" << std::endl;
}