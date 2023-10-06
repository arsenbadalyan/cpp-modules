#pragma once
#ifndef __BUREAUCRAT__HPP__
#define __BUREAUCRAT__HPP__

#include <iostream>

class Bureaucrat {

    public:
        Bureaucrat( const std::string &, int );
        Bureaucrat( const Bureaucrat & );
        ~Bureaucrat();

        Bureaucrat & operator=( const Bureaucrat & );


    public:
        std::string& getName( void ) const;
        int getGrade( void ) const;

    public:
        int incrementGrade( void );
        int decrementGrade( void );

    public:
        class GradeTooHighException : public std::exception {
            private:
                const std::string& _msg;
            public:

                GradeTooHighException(const std::string &);
                ~GradeTooHighException();

                const char * what() const throw();
        };

    private:
        const std::string& _name; 
        int _grade;

};

#endif // !__BUREAUCRAT__HPP__