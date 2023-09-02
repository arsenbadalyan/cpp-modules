#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

int main( int, char** ) {

    Animal *obj1 = new Animal();
    obj1->setType("yey");
    Animal obj2;

    obj2 = *(new Animal(obj1));

    std::cout << obj1->getType();
    // std::cout << obj2->getType();
    // const Animal* meta = new Animal();
    // const Animal* dog = new Dog();
    // const Animal* cat = new Cat();
    // std::cout << dog->getType() << " is cat type" << std::endl;
    // std::cout << cat->getType() << " is dog type" << std::endl;

    // dog->makeSound(); //will output the cat sound!
    // cat->makeSound();
        
    // meta->makeSound();

    // std::cout << "------------- Wrong animals below" << std::endl;

    // const WrongAnimal* wrongMeta = new WrongAnimal();
    // const WrongAnimal* wrongCat = new WrongDog();
    // const WrongAnimal* wrongDog = new WrongCat();
    // std::cout << wrongCat->getType() << " is cat type" << std::endl;
    // std::cout << wrongDog->getType() << " is dog type" << std::endl;

    // wrongCat->makeSound();
    // wrongDog->makeSound();

    // wrongMeta->makeSound();

    // std::cout << "----------------------------------" << std::endl;

    // delete meta;
    // delete dog;
    // delete cat;

    // delete wrongMeta;
    // delete wrongCat;
    // delete wrongDog;

    return (0);
}
