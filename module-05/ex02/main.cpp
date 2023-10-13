#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main ( int, char** ) {
    try {
        const Bureaucrat John("John", 135);
        ShrubberyCreationForm form1("garden");

        form1.beSigned(John);
        form1.execute(John);
        John.executeForm(form1);
        std::cout << form1 << std::endl;
    } catch(std::exception & exc) {
        std::cout << exc.what();
    }

    try {
        const Bureaucrat Tom("Tom", 11);
        RobotomyRequestForm form1("RB45");

        form1.beSigned(Tom);
        form1.execute(Tom);
        std::cout << form1 << std::endl;
    } catch(std::exception & exc) {
        std::cout << exc.what();
    }

    try {
        const Bureaucrat Jack("Jack", 3);
        PresidentialPardonForm form1("TEST_0100");

        form1.beSigned(Jack);
        Jack.executeForm(form1);
        std::cout << form1 << std::endl;
    } catch(std::exception & exc) {
        std::cout << exc.what();
    }
    return (0);
}