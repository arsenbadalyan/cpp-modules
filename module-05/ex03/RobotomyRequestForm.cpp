#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm ( void ) :
    AForm("unknown", RobotomyRequestForm::MAX_SIGN_GRADE, RobotomyRequestForm::MAX_EXEC_GRADE),
    target("unknown") {}

RobotomyRequestForm::RobotomyRequestForm ( const std::string target ) :
    AForm(target, RobotomyRequestForm::MAX_SIGN_GRADE, RobotomyRequestForm::MAX_EXEC_GRADE),
    target(target) {}

RobotomyRequestForm::RobotomyRequestForm ( const RobotomyRequestForm & target  ) :
    AForm(target.getName(), target.getRequiredSignGrade(), target.getRequiredExecuteGrade()),
    target(target.target) {}

RobotomyRequestForm::~RobotomyRequestForm () {}

RobotomyRequestForm & RobotomyRequestForm::operator=( const RobotomyRequestForm & rhs ) {
    if (this == &rhs)
        return (*this);

    AForm::operator=(rhs);
    this->target = rhs.target;

    return (*this);
}

void RobotomyRequestForm::execute( const Bureaucrat & executor ) const {
    this->canBeExecuted(executor);
    this->isSignedForm();
    
    std::srand(std::time(NULL));

    if (rand() % 2 == 0)
        std::cout << this->getName() << " has been robotomized!" << std::endl;
    else
        std::cout << this->getName() << " hasn't been robotomized!" << std::endl;
}