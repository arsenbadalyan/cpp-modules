#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm ( void ) :
    AForm("unknown", PresidentialPardonForm::MAX_SIGN_GRADE, PresidentialPardonForm::MAX_EXEC_GRADE),
    target("unknown") {}

PresidentialPardonForm::PresidentialPardonForm ( const std::string target ) :
    AForm(target, PresidentialPardonForm::MAX_SIGN_GRADE, PresidentialPardonForm::MAX_EXEC_GRADE),
    target(target) {}

PresidentialPardonForm::PresidentialPardonForm ( const PresidentialPardonForm & target  ) :
    AForm(target.getName(), target.getRequiredSignGrade(), target.getRequiredExecuteGrade()),
    target(target.target) {}

PresidentialPardonForm::~PresidentialPardonForm () {}

PresidentialPardonForm & PresidentialPardonForm::operator=( const PresidentialPardonForm & rhs ) {
    if (this == &rhs)
        return (*this);

    AForm::operator=(rhs);
    this->target = rhs.target;

    return (*this);
}

void PresidentialPardonForm::execute( const Bureaucrat & executor ) const {
    this->canBeExecuted(executor);
    this->isSignedForm();
    
    std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}