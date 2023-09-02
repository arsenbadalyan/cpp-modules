#include "Dog.hpp"

Dog::Dog( void ) : Animal::Animal() {
    std::cout << "Dog * CTOR * was called!" << std::endl;
    this->type = "Dog";
}

Dog::Dog( const Dog& target ) : Animal::Animal(target) {
    std::cout << "Dog * COPY CTOR * was called!" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog * DTOR * was called!" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs) {
    Animal::operator=(rhs);
    std::cout << "Dog * ASSIGNMENT OPERATOR * was called!" << std::endl;

    return (*this);
}

void Dog::makeSound( void ) const {
    std::cout << "Bark!!" << std::endl;
}