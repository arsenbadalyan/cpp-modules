#include "AForm.hpp"

AForm::AForm( void )
    : name("no-name"), isSigned(AForm::INITIAL_SIGN_STATE), requiredSignGrade(Bureaucrat::MAX_GRADE), requiredExecuteGrade(Bureaucrat::MIN_GRADE)  {}

AForm::AForm( std::string const & name, int requiredSignGrade, int requiredExecuteGrade )
    : name(name), isSigned(AForm::INITIAL_SIGN_STATE), requiredSignGrade(requiredSignGrade), requiredExecuteGrade(requiredExecuteGrade) {
        checkGrade(requiredExecuteGrade);
        checkGrade(requiredSignGrade);
}

AForm::AForm( AForm const & target )
    : name(target.name), requiredSignGrade(target.requiredSignGrade), requiredExecuteGrade(target.requiredExecuteGrade) {
    this->isSigned = target.isSigned;
}

AForm::~AForm() {}

AForm & AForm::operator=( AForm const & rhs ) {
    if (this == &rhs)
        return (*this);
    this->isSigned = rhs.isSigned;

    return (*this);
}

std::ostream & operator<<( std::ostream & os, AForm const & target ) {
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

std::string AForm::getName ( void ) const {
    return (this->name);
}

bool AForm::getIsSigned ( void ) const {
    return (this->isSigned);
}

int AForm::getRequiredSignGrade ( void ) const {
    return (this->requiredSignGrade);
}

int AForm::getRequiredExecuteGrade ( void ) const {
    return (this->requiredExecuteGrade);
}

void AForm::setIsSigned( bool state ) {
    this->isSigned = state;
}

void AForm::checkGrade ( int grade ) const {
    if (grade < Bureaucrat::MAX_GRADE)
        throw AForm::GradeTooHighException();
    if (grade > Bureaucrat::MIN_GRADE)
        throw AForm::GradeTooLowException();
}

void AForm::executeForm( Bureaucrat const & target ) const {
    this->execute(target);
}

void AForm::beSigned( Bureaucrat const & target ) {
    if (target.getGrade() <= this->getRequiredSignGrade())
        setIsSigned(true);
    else
        throw AForm::GradeTooLowException();
}

void AForm::canBeExecuted( Bureaucrat const & target ) const {
    if (!(target.getGrade() <= this->getRequiredExecuteGrade()))
        throw AForm::GradeTooLowException();
}

void AForm::isSignedForm( void ) const {
    if (!this->getIsSigned())
        throw std::runtime_error("Form cannot be signed, please sign and come back!\n");
}

// Throwing Exceptions --------------------------------

const char * AForm::GradeTooHighException::what ( void ) const throw() {
    return (this->_errMsg.c_str());
}

const char * AForm::GradeTooLowException::what ( void ) const throw() {
    return (this->_errMsg.c_str());
}