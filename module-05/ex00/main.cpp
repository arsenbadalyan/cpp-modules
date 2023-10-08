#include <iostream>
#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1("B1", 15);
        Bureaucrat b2("B2", 150);
        Bureaucrat b3("B3", 1);

        std::cout << b1.getName() << " " << b1.getGrade() << std::endl;
        std::cout << b2.getName() << " " << b2.getGrade() << std::endl;
        // b2.decrementGrade();
        // b3.incrementGrade();
        std::cout << b3.getName() << " " << b3.getGrade() << std::endl;
    } catch( const std::exception& exc ) {
        std::cout << exc.what();
    }
    return (0);
}