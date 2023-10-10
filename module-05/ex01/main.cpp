#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ( int, char** ) {
    try {
        const Bureaucrat * John = new Bureaucrat("John", 11);
        Form * A88 = new Form("A88", 15, 140);

        std::cout << *John;
        std::cout << *A88;

        John->signForm(*A88);
    
        delete John;
        delete A88;
    } catch (std::exception & reason) {
        std::cout << reason.what();
    }
    return (0);
}