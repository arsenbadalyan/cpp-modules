#include "Cat.hpp"

Cat::Cat( void ) : Animal::Animal() {
    std::cout << "Cat * CTOR * was called!" << std::endl;
    this->type = "Cat";
    this->_brain = new Brain();
}

Cat::Cat( const Cat& target ) : Animal::Animal(target) {
    std::cout << "Cat * COPY CTOR * was called!" << std::endl;
    this->_brain = 0;
    Cat::operator=(target);
}

Cat::~Cat() {
    std::cout << "Cat * DTOR * was called!" << std::endl;
    delete this->_brain;
}

Cat& Cat::operator=(const Cat& rhs) {
    Animal::operator=(rhs);
    std::cout << "Cat * ASSIGNMENT OPERATOR * was called!" << std::endl;
    delete this->_brain;
    this->_brain = new Brain(*(rhs._brain));
    *(this->_brain) = *(rhs._brain);

    return (*this);
}

Brain& Cat::getBrain( void ) const {
    return (*(this->_brain));
}

void Cat::makeSound( void ) const {
    std::cout << "Meow!!" << std::endl;
}