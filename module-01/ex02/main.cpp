#include <iostream>

int main( void )
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *brainPTR = &brain;
	std::string &brainREF = brain;

	// Printing mem address
	std::cout << "Printing by memory." << std::endl;
	std::cout << "Variable:  " << &brain << std::endl;
	std::cout << "Pointer:   " << brainPTR << std::endl;
	std::cout << "Reference: " << &brainREF << std::endl;

	// Printing by value
	std::cout << std::endl;
	std::cout << "Printing by value." << std::endl;
	std::cout << "Variable:  " << brain << std::endl;
	std::cout << "Pointer:   " << *brainPTR << std::endl;
	std::cout << "Reference: " << brainREF << std::endl;

	return (0); 
}