#include "Form.hpp"

Form::Form( void )
    : name("no-name"), isSigned(Form::INITIAL_SIGN_STATE), requiredSignGrade(Bureaucrat::MAX_GRADE), requiredExecuteGrade(Bureaucrat::MIN_GRADE)  {}

Form::Form( std::string const & name, int requiredSignGrade, int requiredExecuteGrade )
    : name(name), isSigned(Form::INITIAL_SIGN_STATE), requiredSignGrade(requiredSignGrade), requiredExecuteGrade(requiredExecuteGrade) {
        checkGrade(requiredExecuteGrade);
        checkGrade(requiredSignGrade);
}

Form::Form( Form const & target )
    : name(target.name), requiredSignGrade(target.requiredSignGrade), requiredExecuteGrade(target.requiredExecuteGrade) {
    this->isSigned = target.isSigned;
}

Form::~Form() {}

Form & Form::operator=( Form const & rhs ) {
    if (this == &rhs)
        return (*this);
    this->isSigned = rhs.isSigned;

    return (*this);
}

std::ostream & operator<<( std::ostream & os, Form const & target ) {
    os << target.getName()
        << " form state is - signed: "
        << (target.getIsSigned() ? "yes" : "no")
        << ", required sign grade: "
        << target.getRequiredSignGrade()
        << ", required execute grade: "
        << target.getRequiredExecuteGrade()
        << std::endl;

    return (os);
}

std::string Form::getName ( void ) const {
    return (this->name);
}

bool Form::getIsSigned ( void ) const {
    return (this->isSigned);
}

int Form::getRequiredSignGrade ( void ) const {
    return (this->requiredSignGrade);
}

int Form::getRequiredExecuteGrade ( void ) const {
    return (this->requiredExecuteGrade);
}

void Form::setIsSigned( bool state ) {
    this->isSigned = state;
}

void Form::checkGrade ( int grade ) const {
    if (grade < Bureaucrat::MAX_GRADE)
        throw Form::GradeTooHighException();
    if (grade > Bureaucrat::MIN_GRADE)
        throw Form::GradeTooLowException();
}

void Form::beSigned( Bureaucrat const & target ) {
    if (target.getGrade() <= this->getRequiredSignGrade())
        setIsSigned(true);
    else
        throw Form::GradeTooLowException();
}

// Throwing Exceptions --------------------------------

const char * Form::GradeTooHighException::what ( void ) const throw() {
    return (this->_errMsg.c_str());
}

const char * Form::GradeTooLowException::what ( void ) const throw() {
    return (this->_errMsg.c_str());
}