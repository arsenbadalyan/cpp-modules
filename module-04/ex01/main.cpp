#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

#include "Brain.hpp"

int main( int, char** ) {

    Dog* dog = new Dog();
    Dog* dog1 = new Dog(*(dog));

    dog->getBrain().ideas[0] = "some idea";
    *(dog1) = *(dog);

    std::cout << "<<<<<<<<<<< LOGS" << std::endl;
    std::cout << dog->getBrain().ideas[0] << " - " << dog1->getBrain().ideas[0] << std::endl;
    std::cout << "<<<<<<<<<<< END OF LOGS" << std::endl;

    delete dog1;
    delete dog;
    return (0);
}
