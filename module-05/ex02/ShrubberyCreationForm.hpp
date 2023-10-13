#pragma once
#ifndef __ShrubberyCreationForm__HPP__
#define __ShrubberyCreationForm__HPP__

#include <iostream>
#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm;

class ShrubberyCreationForm
    : public AForm {
    public:
        ShrubberyCreationForm( void );
        ShrubberyCreationForm( const std::string );
        ShrubberyCreationForm( const ShrubberyCreationForm & );
        ~ShrubberyCreationForm();
    
    public:
        ShrubberyCreationForm & operator=( const ShrubberyCreationForm & );

    public:
        void execute( Bureaucrat const & ) const;

    public:
        static const int MAX_SIGN_GRADE = 145;
        static const int MAX_EXEC_GRADE = 137;

    private:
        std::string target;
};

#endif // !__ShrubberyCreationForm__HPP__