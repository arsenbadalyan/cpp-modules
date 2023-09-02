#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal::WrongAnimal() {
    std::cout << "WrongCat * CTOR * was called!" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat( const WrongCat& target ) : WrongAnimal::WrongAnimal(target) {
    std::cout << "WrongCat * COPY CTOR * was called!" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat * DTOR * was called!" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs) {
    WrongAnimal::operator=(rhs);
    std::cout << "WrongCat * ASSIGNMENT OPERATOR * was called!" << std::endl;

    return (*this);
}

void WrongCat::makeSound( void ) const {
    std::cout << "Meow!!" << std::endl;
}