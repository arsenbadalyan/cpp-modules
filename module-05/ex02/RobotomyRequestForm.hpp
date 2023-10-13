#pragma once
#ifndef __RobotomyRequestForm__HPP__
#define __RobotomyRequestForm__HPP__

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm;

class RobotomyRequestForm
    : public AForm {
    public:
        RobotomyRequestForm( void );
        RobotomyRequestForm( const std::string );
        RobotomyRequestForm( const RobotomyRequestForm & );
        ~RobotomyRequestForm();
    
    public:
        RobotomyRequestForm & operator=( const RobotomyRequestForm & );

    public:
        void execute( Bureaucrat const & ) const;

    public:
        static const int MAX_SIGN_GRADE = 72;
        static const int MAX_EXEC_GRADE = 45;

    private:
        std::string target;
};

#endif // !__RobotomyRequestForm__HPP__