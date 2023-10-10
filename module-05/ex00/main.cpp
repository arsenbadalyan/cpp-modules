#include <iostream>
#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1("B1", 15);

        std::cout << b1;
        b1.incrementGrade();
        b1.incrementGrade();
        b1.incrementGrade();
        std::cout << b1;
        b1.decrementGrade();
        std::cout << b1;
    } catch( const std::exception& exc ) {
        std::cout << "Error: " << exc.what();
    }
    try {
        Bureaucrat b2("B2", 150);

        std::cout << b2;
        b2.decrementGrade();
    } catch( const std::exception& exc ) {
        std::cout << "Error: " << exc.what();
    }
    try {
        Bureaucrat b3("B3", 2);

        std::cout << b3;
        b3.incrementGrade();
        b3.incrementGrade();
    } catch( const std::exception& exc ) {
        std::cout << "Error: " << exc.what();
    }
    return (0);
}