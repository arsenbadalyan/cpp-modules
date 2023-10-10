#pragma once
#ifndef __FORM__HPP__
#define __FORM__HPP__

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    public:
        Form( std::string const &, int, int );
        Form( Form const & );
        ~Form();
    
    public:
        Form & operator=( Form const & );
    
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

    private:
        Form( void );

    private:
        void checkGrade( int ) const;

    private:
        std::string const name;
        bool isSigned;
        int const requiredSignGrade;
        int const requiredExecuteGrade;
};

std::ostream& operator<<( std::ostream&, Form const & );

#endif // !__FORM__HPP__