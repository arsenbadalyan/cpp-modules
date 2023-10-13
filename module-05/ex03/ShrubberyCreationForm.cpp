#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm ( void ) :
    AForm("unknown", ShrubberyCreationForm::MAX_SIGN_GRADE, ShrubberyCreationForm::MAX_EXEC_GRADE),
    target("unknown") {}

ShrubberyCreationForm::ShrubberyCreationForm ( const std::string target ) :
    AForm(target, ShrubberyCreationForm::MAX_SIGN_GRADE, ShrubberyCreationForm::MAX_EXEC_GRADE),
    target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm ( const ShrubberyCreationForm & target  ) :
    AForm(target.getName(), target.getRequiredSignGrade(), target.getRequiredExecuteGrade()),
    target(target.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm () {}

ShrubberyCreationForm & ShrubberyCreationForm::operator=( const ShrubberyCreationForm & rhs ) {
    if (this == &rhs)
        return (*this);

    AForm::operator=(rhs);
    this->target = rhs.target;

    return (*this);
}

void ShrubberyCreationForm::execute( const Bureaucrat & executor ) const {
    this->canBeExecuted(executor);
    this->isSignedForm();
    
    std::ofstream drawFile;

    drawFile.open((this->getName() + "_shrubbery").c_str(), std::ios::out | std::ios::trunc);

    if (!drawFile)
        throw std::runtime_error("Cannot open file\n");

    drawFile << "                  v .   ._, |_  .," << std::endl;
    drawFile << "           `-._\\/  .  \\ /    |/_" << std::endl;
    drawFile << "               \\  _\\, y | \\//" << std::endl;
    drawFile << "         _\\_.___\\, \\/ -.\\||" << std::endl;
    drawFile << "           `7-,--.`._||  / / ," << std::endl;
    drawFile << "           /'     `-. `./ / |/_.'" << std::endl;
    drawFile << "                     |    |//" << std::endl;
    drawFile << "                     |_    /" << std::endl;
    drawFile << "                     |-   |" << std::endl;
    drawFile << "                     |   =|" << std::endl;
    drawFile << "                     |    |" << std::endl;
    drawFile << "--------------------/ ,  . \\--------._" << std::endl;

    drawFile.close();
}