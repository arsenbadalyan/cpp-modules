#include "Cat.hpp"

Cat::Cat( void ) : Animal::Animal() {
    std::cout << "Cat * CTOR * was called!" << std::endl;
    this->type = "Cat";
}

Cat::Cat( const Cat& target ) : Animal::Animal(target) {
    std::cout << "Cat * COPY CTOR * was called!" << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat * DTOR * was called!" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs) {
    Animal::operator=(rhs);
    std::cout << "Cat * ASSIGNMENT OPERATOR * was called!" << std::endl;

    return (*this);
}

void Cat::makeSound( void ) const {
    std::cout << "Meow!!" << std::endl;
}