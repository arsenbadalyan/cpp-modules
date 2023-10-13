#pragma once
#ifndef __PresidentialPardonForm__HPP__
#define __PresidentialPardonForm__HPP__

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm;

class PresidentialPardonForm
    : public AForm {
    public:
        PresidentialPardonForm( void );
        PresidentialPardonForm( const std::string );
        PresidentialPardonForm( const PresidentialPardonForm & );
        ~PresidentialPardonForm();
    
    public:
        PresidentialPardonForm & operator=( const PresidentialPardonForm & );

    public:
        void execute( Bureaucrat const & ) const;

    public:
        static const int MAX_SIGN_GRADE = 25;
        static const int MAX_EXEC_GRADE = 5;

    private:
        std::string target;
};

#endif // !__PresidentialPardonForm__HPP__