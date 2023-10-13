#pragma once
#ifndef __AFORM__HPP__
#define __AFORM__HPP__

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    public:
        AForm( std::string const &, int, int );
        AForm( AForm const & );
        virtual ~AForm();
    
    public:
        AForm & operator=( AForm const & );
    
    public:
        static bool const INITIAL_SIGN_STATE = false;

    public: // getters
        std::string getName( void ) const;
        bool getIsSigned( void ) const;
        int getRequiredSignGrade( void ) const;
        int getRequiredExecuteGrade( void ) const;

    public: // setters
        void setIsSigned( bool );

    public:
        void beSigned( Bureaucrat const & );
        void isSignedForm( void ) const;
        void canBeExecuted( Bureaucrat const & ) const;
        void executeForm( Bureaucrat const & ) const;
    
    public:
        class GradeTooLowException : public std::exception {
            private:
                std::string _errMsg;
            public:
                GradeTooLowException() : _errMsg("Grade is too low!\n") {}
                ~GradeTooLowException() throw() {};
            public:
                const char * what() const throw();
        };

        class GradeTooHighException : public std::exception {
            private:
                std::string _errMsg;
            public:
                GradeTooHighException() : _errMsg("Grade is too high!\n") {}
                ~GradeTooHighException() throw() {};
            public:
                const char * what() const throw();
        };

    protected:
        virtual void execute( Bureaucrat const & ) const = 0;

    private:
        AForm( void );

    private:
        void checkGrade( int ) const;

    private:
        std::string const name;
        bool isSigned;
        int const requiredSignGrade;
        int const requiredExecuteGrade;
};

std::ostream& operator<<( std::ostream&, AForm const & );

#endif // !__AFORM__HPP__