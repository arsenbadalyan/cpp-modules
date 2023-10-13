#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main ( int, char** ) {
    try {
        const Bureaucrat Jack("Jack", 3);
        Intern Tom;

        AForm * treeForm = Tom.makeForm("shrubberyCreation request", "newTree");

        treeForm->beSigned(Jack);
        Jack.executeForm(*treeForm);

        std::cout << *treeForm << std::endl;

        delete treeForm;
    } catch(std::exception & exc) {
        std::cout << exc.what();
    }
    return (0);
}