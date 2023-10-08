#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat ( void ) : _name("no-name"), _grade(Bureaucrat::MIN_GRADE) {}

Bureaucrat::Bureaucrat ( const std::string& name, int grade ) : _name(name) {
    this->setGrade(grade);
}

Bureaucrat::Bureaucrat ( const Bureaucrat& target ) : _name(target._name) {
    this->_grade = target._grade;
}

Bureaucrat::~Bureaucrat () {}

Bureaucrat& Bureaucrat::operator= ( const Bureaucrat& rhs ) {
    if (this == &rhs)
        return (*this);
    
    this->_grade = rhs._grade;

    return (*this);
}

std::string Bureaucrat::getName( void ) const {
    return (this->_name);
}

int Bureaucrat::getGrade( void ) const {
    return (this->_grade);
}

void Bureaucrat::incrementGrade( void ) {
    int newGrade = this->getGrade() - 1;
    this->setGrade(newGrade);
}

void Bureaucrat::decrementGrade( void ) {
    int newGrade = this->getGrade() + 1;
    this->setGrade(newGrade);
}

void Bureaucrat::setGrade( int grade ) {
    if (grade < Bureaucrat::MAX_GRADE)
        throw Bureaucrat::GradeTooHighException();
    if (grade > Bureaucrat::MIN_GRADE)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
}

// Throwing Exceptions --------------------------------

const char * Bureaucrat::GradeTooHighException::what ( void ) const throw() {
    return (std::runtime_error("Grade is too hight!").what());
}

const char * Bureaucrat::GradeTooLowException::what ( void ) const throw() {
    return (std::runtime_error("Grade is too low!").what());
}