#include "Dog.hpp"

Dog::Dog( void ) : Animal::Animal() {
    std::cout << "Dog * CTOR * was called!" << std::endl;
    this->type = "Dog";
    this->_brain = new Brain();
}

Dog::Dog( const Dog& target ) : Animal::Animal(target) {
    std::cout << "Dog * COPY CTOR * was called!" << std::endl;
    this->_brain = 0;
    Dog::operator=(target);
}

Dog::~Dog() {
    std::cout << "Dog * DTOR * was called!" << std::endl;
    delete this->_brain;
}

Dog& Dog::operator=(const Dog& rhs) {
    Animal::operator=(rhs);
    std::cout << "Dog * ASSIGNMENT OPERATOR * was called!" << std::endl;
    delete this->_brain;
    this->_brain = new Brain(*(rhs._brain));

    return (*this);
}

Brain& Dog::getBrain( void ) const {
    return (*(this->_brain));
}

void Dog::makeSound( void ) const {
    std::cout << "Bark!!" << std::endl;
}