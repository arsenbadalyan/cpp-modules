#pragma once
#ifndef __BUREAUCRAT__HPP__
#define __BUREAUCRAT__HPP__

#include <iostream>

class Bureaucrat {

    public:
        Bureaucrat( void );
        Bureaucrat( const std::string &, int );
        Bureaucrat( const Bureaucrat & );
        ~Bureaucrat();

        Bureaucrat & operator=( const Bureaucrat & );

    public: // getters
        std::string getName( void ) const;
        int getGrade( void ) const;

    public: //setters
        void setGrade( int );

    public:
        void incrementGrade( void );
        void decrementGrade( void );

    public:
        static const int MAX_GRADE = 1;
        static const int MIN_GRADE = 150;

    public:
        class GradeTooHighException : public std::exception {
            public:
                const char * what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char * what() const throw();
        };

    private:
        const std::string _name;
        int _grade;

};

#endif // !__BUREAUCRAT__HPP__