#include "Intern.hpp"

Intern::Intern ( void ) {}

Intern::Intern ( const Intern & ) {}

Intern::~Intern () {}

Intern& Intern::operator= ( const Intern& ) {
    return (*this);
}

AForm * Intern::makeForm( std::string formName, std::string target ) {
    const size_t ctors_length = 3;
    const std::string constructorNames[ctors_length] = { "robotomy request", "presidentialPardon request", "shrubberyCreation request" };
    AForm * constructorsList[ctors_length] = { new RobotomyRequestForm(target), new PresidentialPardonForm(target), new ShrubberyCreationForm(target) };
    AForm * result = NULL;

    for (size_t i = 0; i < ctors_length; i++) {
        if (constructorNames[i] == formName)
            result = constructorsList[i];
        else
            delete constructorsList[i];
    }

    if (!result)
        throw std::runtime_error("There are no any form constructor specified!\n");

    return (result);
}