#pragma once
#ifndef __BUREAUCRAT__HPP__
#define __BUREAUCRAT__HPP__

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat {

    public:
        Bureaucrat( void );
        Bureaucrat( const std::string &, int );
        Bureaucrat( const Bureaucrat & );
        ~Bureaucrat();

    public:
        Bureaucrat & operator=( const Bureaucrat & );

    public: // getters
        std::string getName( void ) const;
        int getGrade( void ) const;

    public: //setters
        void setGrade( int );

    public:
        void incrementGrade( void );
        void decrementGrade( void );
        void signForm( AForm & ) const;
        void executeForm( AForm const & ) const;

    public:
        static const int MAX_GRADE = 1;
        static const int MIN_GRADE = 150;

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
        const std::string _name;
        int _grade;

};

std::ostream& operator<<( std::ostream &, const Bureaucrat & );

#endif // !__BUREAUCRAT__HPP__