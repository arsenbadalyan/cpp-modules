#include <iostream>
#include "Base.hpp"

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned>(std::time(0)));

    // Generate a random number between 1 and 3
    int borderNum = 3;
    int randomNumber = (std::rand() % borderNum);

    Base * list[] = { new A(), new B(), new C() };

    for (int i = 0; i < borderNum; i++) {
        if (i != randomNumber)
            delete list[i];
    }

    return (list[randomNumber]);
}

void identify(Base* p) {

    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;

    if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;

    if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p) {

    if (dynamic_cast<A*>(&p))
        std::cout << "A" << std::endl;

    if (dynamic_cast<B*>(&p))
        std::cout << "B" << std::endl;

    if (dynamic_cast<C*>(&p))
        std::cout << "C" << std::endl;

}

int main( int, char ** ) {
    
    try {
        Base * someRandomPtr = generate();
        identify(*someRandomPtr);
        identify(someRandomPtr);
    } catch ( std::exception & exc ) {
        std::cout << "Exception thrown reason is: " << exc.what() << std::endl;
    }

    return (0);
}