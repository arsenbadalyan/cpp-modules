#include "Harl.hpp"

// Public member functions
void Harl::complain( std::string level ) {
	size_t			currentIndex = 0;
	const size_t	functionListSize = 4;
	std::string		functionNames[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	while (currentIndex < functionListSize && level != functionNames[currentIndex]) { currentIndex++; }

	switch (currentIndex) {
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break;
		default:
			std::cout << std::endl << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}

}

// Private member functions
void Harl::debug( void ){
	std::cout << "\e[32m" << std::endl;
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
	std::cout << "\033[0m";
}

void Harl::info( void ) {
	std::cout << "\033[34m" << std::endl;
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	std::cout << "\033[0m";
}

void Harl::warning( void ) {
	std::cout << "\033[33m" << std::endl;
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
	std::cout << "\033[0m";
}

void Harl::error( void ) {
	std::cout << "\033[31m" << std::endl;
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << "\033[0m";
}