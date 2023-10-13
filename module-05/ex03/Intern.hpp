#pragma once
#ifndef __INTERN__HPP__
#define __INTERN__HPP__

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class AForm;

class Intern {

    public:
        Intern( void );
        Intern( const Intern & );
        ~Intern();

    public:
        Intern & operator=( const Intern & );

    public:
        AForm * makeForm( std::string, std::string );
};

#endif // !__INTERN__HPP__